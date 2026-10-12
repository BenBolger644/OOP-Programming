# Chapter 2 · Practical Lab 2 · Evidence
## Beacon pool console

Name or student identifier: [complete]

Date (YYYY-MM-DD): [complete]

Repository URL, if used: [complete / not used]

Visual Studio version: [complete]

Platform Toolset: v145 · Language: C++17 · Configuration: Debug · Platform: x64

---

## How to use this evidence record

Complete this file **while you work through the lab**.

Keep answers short. You do not need to invent a separate test suite, use `assert`, or create extra screenshots. The practical already gives you the calls and expected console results needed for the core checks.

When the lab asks for a prediction, write it down before you run the program. If your prediction is wrong, correct the code or your explanation and continue.

---

## 01 · Project setup

**Project name:**

[complete]

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

[yes / no]

If no, briefly record the problem you fixed:

[complete / not applicable]

---

## 02 · Receiver and Beacon

The receiver uses a `Beacon const&` parameter but does not contain a `Beacon` by value.

**Why is this enough in `Receiver.h`?**

```cpp
class Beacon;
```

[one sentence]

**Which files did you include in `Receiver.cpp` before calling `t_beacon.x()`?**

[complete]

**Prediction before running:**

A receiver at 35 and a beacon at 10 should have range: [complete]

**Actual output:**

```text
[copy the Connection check output here]
```

**Status:**

[not started / working / complete]

---

## 03 · BeaconPool composition

`BeaconPool` contains:

```cpp
Beacon m_beacons[CAPACITY];
```

**Why does `BeaconPool.h` need the complete `Beacon` definition rather than only a forward declaration?**

[one or two sentences]

**What does this declaration permit?**

```cpp
friend class BeaconPool;
```

[one sentence]

**Does friendship itself make `BeaconPool` own a `Beacon`?**

[yes / no, followed by one short explanation]

**Status:**

[not started / working / complete]

---

## 04 · Request logic

For a valid request, the pool should activate the first free slot.

### Published sequence

**My prediction before running:**

- request 30 -> slot [complete]
- request 60 -> slot [complete]
- request 90 -> slot [complete]
- request 50 when full -> slot [complete]

**Actual values:**

- request 30 -> slot [complete]
- request 60 -> slot [complete]
- request 90 -> slot [complete]
- request 50 when full -> slot [complete]

**What range of signal strengths does your `request()` accept?**

[complete]

**When should `s_successfulRequests` increase?**

[one sentence]

**Status:**

[not started / working / complete]

---

## 05 · Release and reuse

The core sequence releases the second checkout and then requests a new strength of 75.

**Prediction before running:**

- released slot: [complete]
- released result: [complete]
- strength after release: [complete]
- reused slot: [complete]

**Actual result:**

```text
[copy the Release and reuse output here]
```

**Why does `reset()` clear the strength as well as the active flag?**

[one sentence]

**Why must `release()` validate the index before accessing the array?**

[one sentence]

**Status:**

[not started / working / complete]

---

## 06 · Per-object state and shared state

Before running the second-pool experiment, complete the predictions.

**Pool B starts with active count:**

[complete]

**Its first successful request should use slot:**

[complete]

**Should using Pool B change Pool A's active count?**

[complete]

**Expected shared successful-request tally after the Pool B request:**

[complete]

**Actual output:**

```text
[copy the Pool B output here]
```

Complete the statements:

`m_beacons` is ____________________ state because each `BeaconPool` object has its own array.

`s_successfulRequests` is ____________________ state because every `BeaconPool` object refers to the same tally.

---

## 07 · Boundary check

Use a fresh `BeaconPool` and temporarily request strength `0`.

**Prediction:**

- returned slot: [complete]
- active count afterwards: [complete]
- should the shared tally increase? [complete]

**Actual result:**

[complete]

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
[complete]
```

**Does it match?**

[yes / no]

If no, record the remaining difference:

[complete / not applicable]

---

## Short understanding check

Answer each in one or two sentences.

**1. Why can `Receiver.h` forward-declare `Beacon`?**

[complete]

**2. Why can `BeaconPool.h` not use only the same forward declaration for its array?**

[complete]

**3. What does `friend class BeaconPool;` grant, and what does it not grant?**

[complete]

**4. Why are `poolA` and `poolB` independent even though they use the same class?**

[complete]

**5. Why can `successfulRequests()` be called using `BeaconPool::successfulRequests()`?**

[complete]

---

## One problem I fixed

Complete this only if you encountered a genuine problem.

**What went wrong?**

[complete / no problem recorded]

**What did I change?**

[complete / not applicable]

**What happened after rebuilding?**

[complete / not applicable]

Do not invent an error if you did not encounter one.

---

## Optional stretch · `full()`

Complete only if attempted.

**Did you add `bool full() const;`?**

[yes / no / not attempted]

**Expected results:**

- new pool: `false`
- after three successful requests: `true`
- after one release: `false`

**Actual results:**

[complete / not attempted]

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

[complete]
