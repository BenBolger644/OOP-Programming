# Practical Lab 1 — evidence

Repository URL: https://github.com/BenBolger644/OOP-Programming/tree/main/Lab1
Final commit identifier: "Finishing Push to Github"
Build configuration:Debug, x64, C++17 Visual Studio 2022, v143 toolset
Known unfinished requirements: None

## A — Structure and diagnosis

| Fault | First useful diagnostic | Stage and cause | Repair | Verified result |
| --- | --- | --- | --- | --- |
| 1 |syntax error: missing ';' before 'Banner::show' in Main.cpp|Compiler|Added semi colon to end of 'int packageCount = 3'|Moved on to next error|
| 2 |1 unresolved externals
unresolved external symbol "void __cdecl Banner::show(void)" (?show@Banner@@YAXXZ) referenced in function main|Linker|Changed 'display()' to 'show()'|The build compiled and everything ran correctly.|

Final successful build and output:
    Dispatch Diagnostic
    Packages: 3

Build explanation (maximum 80 words): I built DispatchAudit in Visual Studio 2022 using C++17 and the MSVC v143 compiler, debug x64. Main.cpp can call Dispatch::printHeading because it includes Dispatch.h, which declares the function. I wrote the definition in Dispatch.cpp, and the linker matches it when each file is compiled. Build recompiles only the changed files whereas Rebuild cleans everything and recompiles all of it.

## B — Input recovery

Explain the different jobs of state reset and input removal (two sentences): 'std::cin.clear()' resets the streams fail state so it will accept further attempts at reading while not removing anything from the input. 'std:cin.ignore()' removes the unread characters I don't want up to the newline, to avoid an infinity loop with the same text being read again and again forever.

## D — Pointer trace

Use observed address values or symbolic labels that identify the same objects consistently.

| State | totalStock | availableStock | dispatchCount | Selected object | Stored pointer value | Pointer's own address | Dereferenced value, if valid |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Before stock update |40|40|0|availableStock|0x00000085070ffbb4|0x00000085070ffbe8|40|
| After stock update |40|15|0|availableStock|0x0000008507ffbb4|0x0000008507ffbe8|15|
| After retargeting/increment |40|15|1|dispatchCount|0x00000085070ffbd4|0x00000085070ffbe8|1|
| After null reset |40|15|1|none|0x0000000000000000|0x00000085070ffbe8| Not evaluated |

Explain selectedQuantity, *selectedQuantity and &selectedQuantity: selectedQuantity is the pointer itself, it holds an address, not either of our integers like 15 or 40. *selectedQuantity means to go to that address and look inside, it gives the actual value, like our 40 before the update and the 15 after. &selectedQuantity is the address of the pointer itself, not the value it points to. In my trace this stayed as 0x00000085070ffbe8 the whole time, even when the pointer was rewritten to point at a different address.

Explain ownership and why non-null is not a universal safety guarantee: selectedQuantity never used new, it doesn't own availableStock or dispatchCount, it just points at the already existing variables in main(). if I had written delete selectedQuantity, it would try to free memory that was never allocated with new, which is undefined behaviour. For the second question, a pointer can be non-null but still unsafe, as an example if it kept pointing at a local variable from that has already finmished, the address would still look like a valid, non null number but the memory it points to is no longer valid when reading.

## E — Tests

Record predictions before running. Do not claim a test passed unless you ran it.

| ID | Input/data | Expected | Actual/exit status | Pass/fail | Interpretation |
| --- | --- | --- | --- | --- | --- |
| P1 |normal.txt (12,0,8,20); North Depot, 25|batches 4, low 2, original 40, remaining 15, count 1|(process 20588) exited with code 0 (0x0).|Pass|Confirms baseline dispatch and pointer logic work together correctly|
| P2 |short-stack.txt (4,6); North Depot, 25|batches 2, low 2, original 10, remaining 0, count 1|(process 23144) exited with code 0 (0x0).|Pass|Confirms a shortage dispatches available stock rather than the full request|
| P3 |normal.txt (12,0,8,20); North Depot, 0|batches 4, low 2, original 40, remaining 40, count 0|(process 7036) exited with code 0 (0x0).|Pass|Confirms a request of 0 dispatches nothing and leaves stock unchanged, and the dispatch counter doesnt change when nothing is dispatched.|
| P4 |normal.txt (12,0,8,20): North Depot, abc, then 80, then 25abc|two retries, (abc rejected as unreachable, 80 is out of range) 25 accepted, batch 4, low 2, original 40, remaining 15, count 1|(process 7036) exited with code 0 (0x0).|Pass|Confirms the recovery loop distinguishes unreadable from out of range entries and both are correctly offered witha retry|
| P5 |normal.txt (12, 0, 8, 20); North Depot, 25|"Error: could not open batches.txt" printed and program exits with non-zero (1) and no completed report|(process 4056) exited with code 1 (0x1).|Pass|Confirms an open is reported properly and stops the program before any report is attempted.|
| P6 |empty.txt (); North Depot, 25|"No Batches Found" error printed, exit code of 1 and no completed report|(process 14908) exited with code 0 (0x0).|Pass|Confirms an empty file is treated as its own error from the missing file.|
| P7 |malformed-final.txt (12 8 +); North Depot, 25|Invalid Data Error, exit 1, no completed report|(process 15596) exited with code 1 (0x1).|Pass|Confirms malformed entries return invalid data rather than mistaken for a clean end of file|
| P8 — own case |out-of-range.txt (12, 41); North Depot, 25|Invalid batch value error with an exit of 1 and no completed report|(process 10388) exited with code 1 (0x1).|Pass|Confirms a value one above the maximum is correctly rejected and program is terminated|

Why does the extra test detect something the baseline does not?

Final baseline restored: Yes, Batches.txt contains 12, 0, 8, 20
Both projects build / recorded limitations: Both DispatchAudit and BuildInvestigation build successfully with no known limitations
Source snapshot and evidence submitted: Yes, commited and pushed to https://github.com/BenBolger644/OOP-Programming/tree/main/Lab1, source ZIP and Evidence.md complete
