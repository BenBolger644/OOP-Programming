# Chapter 03 – Practical Lab 03 – Evidence
## Arena Object Inspector

**Student ID:** c00324085
**Date (YYYY-MM-DD):** 15/11/2026
**Visual Studio version:** v2026
*Repository link (if used):** [complete / not used]

Build settings: v145 · C++17 · `/W4` · `/GR` · `/EHsc` · Debug · x64

Complete this file as you work. Short answers and relevant console excerpts are enough. Do not invent extra tests or take screenshots unless your lecturer specifically requests them. Never run an unsafe cast or a dangling-pointer experiment.

---

## 01 · Project setup

- [ ] Created an Empty Project named `ArenaObjectInspectorLab`.
- [ ] Added `Main.cpp`, `ArenaObjects.h`, `ArenaObjects.cpp`, `Inspector.h` and `Inspector.cpp`.
- [ ] Selected C++17, `/W4`, `/GR`, `/EHsc`, Debug and x64.
- [ ] The starting project built and printed `Arena object inspector`.

**If a build problem occurred, what did you fix?** 
No Build problem occurred

## 02 · Shared virtual behaviour

**Which class is abstract, and why?**  
ArenaObject because report() is pure virtual so it cant be constructed directly.

**What does `EliteGuard` inherit from `Guard`?**  
inherits its health

**Shared behaviour output:**

```text
Shared Behaviour
Guard health: 60
Elite Guard health: 90, bonus: 15
Supply Crate Items: 4
```

**Why can `selected->report()` call the correct function for all three objects?**  
report() is virtual so the call is from whatever object selected points to

## 03 · Checked Guard views

Before running, predict what `readGuardHealth` returns:

| Argument | My prediction | Actual |
|---|---|---|
| `&guard` | 60 | 60 |
| `&elite` | 90 | 90 |
| `&crate` | -1 | -1 |
| `nullptr` | -1 | -1 |

**Why must the cast result be checked before calling `health()`?**  
a failed pointer return nullptr, and calling health() through it is undefined behaviour

**Does a successful cast create a new Guard object or owner?**  
No it gives a checked pointer to the existing objects. There isnt any copying or no ownership

## 04 · Exact types

**Record the five exact-type checks shown in the lab:**

```text
Exact Guard Checks
Guard is exact Guard: true
Elite is exact Guard: false
Elite is exact EliteGuard: true
Crate is exact Guard: false
Pointer is ArenaObject const*: true
```

**Why is `EliteGuard` Guard-compatible but not exactly `Guard`?**  
an EliteGuard contains a guard view so it is valid but the whole object is EliteGuard and not Guard so its not exact

**How do `typeid(selected)` and `typeid(*selected)` differ?**  
the first describes the pointers own type whereas the second give the type of the object it points to

## 05 · Checked references

**Record the two reference-cast results:**

```text
[paste the Reference casts section]
```

**What does a failed checked `Guard const&` conversion do, and which exception is caught?**  
[one sentence]

## 06 · Mixed selection

**Predictions (before running):**

- Guard-compatible objects: [complete]
- Exact Guard objects: [complete]
- Empty selection result: [complete]
- Positive count with null array result: [complete]

**Actual output:**

```text
[paste the Selection section]
```

**Which checks run before indexing the selection array?**  
[one or two sentences]

**Why is a null-element guard required before `typeid(*slot)`?**  
[one sentence]

## 07 · Virtual function definition investigation

**Was the temporary error observed during compilation or linking?**  
[complete]

**What definition was missing?**  
[complete]

**What did you restore to fix the build?**  
[one sentence]

## 08 · Final console output

```text
[paste the complete final output here]
```

- [ ] The output matches the practical's final expected result.
- [ ] The temporary missing-definition experiment has been reversed.
- [ ] The final Debug/x64 project builds successfully.

**One key difference between a compatible derived view and exact runtime type:**  
[one or two sentences]

## Optional stretch · Object size

Only if attempted: record `sizeof` values and compiler/build settings. Explain why they do not establish a portable vtable size or member offset.

[not attempted / measurements and explanation]

---

### Final checklist

- [ ] I wrote and understood the class definitions and member-function bodies.
- [ ] I used `dynamic_cast` with safe failure handling.
- [ ] I compared exact runtime types using `typeid`, not class-name strings.
- [ ] I handled a failed reference cast using `std::bad_cast`.
- [ ] I validated the selection count and skipped null slots.
- [ ] I fixed and documented the missing virtual function definition.
- [ ] I restored the final program and obtained the expected output.
