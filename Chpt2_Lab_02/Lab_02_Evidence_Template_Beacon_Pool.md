# Chapter 2 · Practical Lab 2 · Evidence
## Beacon pool console

Name or student identifier: c00324085

Date (YYYY-MM-DD): 12/10/2026

Repository URL, if used: https://github.com/BenBolger644/OOP-Programming/tree/main/Chpt2_Lab_02

Visual Studio version: VS 2026

Platform Toolset: v145 · Language: C++17 · Configuration: Debug · Platform: x64

---

## How to use this evidence record

Complete this file **while you work through the lab**.

Keep answers short. You do not need to invent a separate test suite, use `assert`, or create extra screenshots. The practical already gives you the calls and expected console results needed for the core checks.

When the lab asks for a prediction, write it down before you run the program. If your prediction is wrong, correct the code or your explanation and continue.

---

## 01 · Project setup

**Project name:**

BeaconPoolLab

**Files created:**

- [ ] `Main.cpp`
- [ ] `Beacon.h`
- [ ] `Beacon.cpp`
- [ ] `Receiver.h`
- [ ] `Receiver.cpp`
- [ ] `BeaconPool.h`
- [ ] `BeaconPool.cpp`

**Build settings checked:**

- [ ] Platform Toolset `v145`
- [ ] C++ Language Standard `ISO C++17`
- [ ] Warning Level `/W4`
- [ ] `Debug`
- [ ] `x64`

**First successful console output:**

```text
Beacon pool lab
```

**Did the starter project build and run successfully?**

yes

If no, briefly record the problem you fixed:

not applicable

---

## 02 · Receiver and Beacon

The receiver uses a `Beacon const&` parameter but does not contain a `Beacon` by value.

**Why is this enough in `Receiver.h`?**

```cpp
class Beacon;
```

A reference only holds an address meaning the compiler needs to know the name which is Beacon, exists. It doesn't need its size or numbers.

**Which files did you include in `Receiver.cpp` before calling `t_beacon.x()`?**

Receiver.h, Beacon.h and <cstdlib> (for std::abs)

**Prediction before running:**

A receiver at 35 and a beacon at 10 should have range: 25

**Actual output:**

```text
Connection Check
Range to beacon: 25
```

**Status:**

Complete

---

## 03 · BeaconPool composition

`BeaconPool` contains:

```cpp
Beacon m_beacons[CAPACITY];
```

**Why does `BeaconPool.h` need the complete `Beacon` definition rather than only a forward declaration?**

The array stores the three Beacon objects by value, meaning the compiler needs Beacon's full size and layout to make BeaconPool. A forward declaration only provides the name and would not be enough.

**What does this declaration permit?**

```cpp
friend class BeaconPool;
```

It lets BeaconPool access Beacons private members such as the private default constructor activate() and reset()

**Does friendship itself make `BeaconPool` own a `Beacon`?**

No, friendship only grants access. Ownership is needed and comes from the array m_beacons.

**Status:**

Complete

---

## 04 · Request logic

For a valid request, the pool should activate the first free slot.

### Published sequence

**My prediction before running:**

- request 30 -> slot 0
- request 60 -> slot 1
- request 90 -> slot 2
- request 50 when full -> slot 1

**Actual values:**

- request 30 -> slot 0
- request 60 -> slot 1
- request 90 -> slot 2
- request 50 when full -> slot 1

**What range of signal strengths does your `request()` accept?**

1 to 100 inclusive. Anything other than this returns -1 and doesn't change anything.

**When should `s_successfulRequests` increase?**

Only when a free slot has been activated and should never for an invalid strength amount or a full pool.

**Status:**

complete

---

## 05 · Release and reuse

The core sequence releases the second checkout and then requests a new strength of 75.

**Prediction before running:**

- released slot: 1
- released result: true
- strength after release: 0
- reused slot: 1

**Actual result:**

```text
Release and reuse
Released slot 1: true
Strength after release: 0
Request: 75 -> slot 1
Active Beacons: 3
Successful requests: 5
```

**Why does `reset()` clear the strength as well as the active flag?**

So a released beacons returns to a clean state and no old values affect the next use of the slot.

**Why must `release()` validate the index before accessing the array?**

an index below 0 would read outside the array, leading to undefined behaviour

**Status:**

complete

---

## 06 · Per-object state and shared state

Before running the second-pool experiment, complete the predictions.

**Pool B starts with active count:**

0

**Its first successful request should use slot:**

0

**Should using Pool B change Pool A's active count?**

No, Pool A stays at 3

**Expected shared successful-request tally after the Pool B request:**

5

**Actual output:**

```text
Pool B
Pool B active: 0
Pool B request 25 -> slot 0
Pool A active: 3
Pool B active 1
Successful requests: 5
```

Complete the statements:

`m_beacons` is per-object state because each `BeaconPool` object has its own array.

`s_successfulRequests` is shared (class wide static) state because every `BeaconPool` object refers to the same tally.

---

## 07 · Boundary check

Use a fresh `BeaconPool` and temporarily request strength `0`.

**Prediction:**

- returned slot: -1
- active count afterwards: 0
- should the shared tally increase? No

**Actual result:**

request(0) returned -1, the active count stayed at 0, and the shared count stayed at 5. 

Restore the final `Main.cpp` afterwards.

---

## Final console check

Your final output should match the practical:

```text
Beacon pool lab

Connection check
Range to beacon: 25

Pool A
Start active: 0
Request 30 -> slot 0
Request 60 -> slot 1
Request 90 -> slot 2
Request 50 -> slot -1
Active beacons: 3
Successful requests: 3

Release and reuse
Released slot 1: true
Strength after release: 0
Request 75 -> slot 1
Active beacons: 3
Successful requests: 4

Pool B
Pool B active: 0
Pool B request 25 -> slot 0
Pool A active: 3
Pool B active: 1
Successful requests: 5
```

**Paste your final console output below:**

```text
Beacon pool lab

Connection check
Range to beacon: 25

Pool A
Start active: 0
Request 30 -> slot 0
Request 60 -> slot 1
Request 90 -> slot 2
Request 50 -> slot -1
Active beacons: 3
Successful requests: 3

Release and reuse
Released slot 1: true
Strength after release: 0
Request 75 -> slot 1
Active beacons: 3
Successful requests: 4

Pool B
Pool B active: 0
Pool B request 25 -> slot 0
Pool A active: 3
Pool B active: 1
Successful requests: 5
```

**Does it match?**

yes

If no, record the remaining difference:

not applicable

---

## Short understanding check

Answer each in one or two sentences.

**1. Why can `Receiver.h` forward-declare `Beacon`?**

Takes it via const reference, so the compiler needs the name but not the layout

**2. Why can `BeaconPool.h` not use only the same forward declaration for its array?**

it contains beacon objects, so the compiler needs the full definition to know their size.

**3. What does `friend class BeaconPool;` grant, and what does it not grant?**

It grants BeaconPool access to Beacons private section. It does not give BeaconPool ownership of any Beacon or give it the beacons size.

**4. Why are `poolA` and `poolB` independent even though they use the same class?**

Each beacon object owns its own m_beacons array, so changing one does not affect the other.

**5. Why can `successfulRequests()` be called using `BeaconPool::successfulRequests()`?**

It is a static member function, so it belongs to the class rather than to one object and doesnt need an object called.

---

## One problem I fixed

Complete this only if you encountered a genuine problem.

**What went wrong?**

The build failed with a linker error because Main.cp called activeCount() before I had written its definition into BeaconPool.cpp

**What did I change?**

I wrote the beaconPool activeCount const definition into BeaconPool.cp. I also corrected the output text and the order of the lines in Main.cpp to match the output.

**What happened after rebuilding?**

The project all linked up and ran as it should.

Do not invent an error if you did not encounter one.

---

## Optional stretch · `full()`

Complete only if attempted.

**Did you add `bool full() const;`?**

Not attempted

**Expected results:**

- new pool: `false`
- after three successful requests: `true`
- after one release: `false`

**Actual results:**

Not attempted

---

## Final checklist

- [ ] I created the solution and project from scratch.
- [ ] All seven source/header files are included in the project.
- [ ] The project builds with v145, C++17, `/W4`, Debug and x64.
- [ ] `Receiver.h` uses a forward declaration of `Beacon`.
- [ ] `Receiver.cpp` includes the complete `Beacon` definition before calling Beacon members.
- [ ] `BeaconPool.h` includes `Beacon.h` because it stores Beacon objects by value.
- [ ] `request()` validates strength, uses the first free slot and returns `-1` when it cannot serve a request.
- [ ] `release()` validates the index and resets released state.
- [ ] `activeCount()` reports the state of one pool only.
- [ ] `successfulRequests()` reports the shared class-wide tally.
- [ ] My final console output matches the practical.
- [ ] Temporary boundary-check edits have been restored.
- [ ] The final project builds successfully.

---

## Final note

One class-relationship concept I can now explain without copying the workbook:

The difference between a forward declaration and a full include.
