# Chapter 2 · Practical Lab 1 · Evidence
## Training bot status console

Name or student identifier: [complete]

Date (YYYY-MM-DD): [complete]

Repository URL, if used: [complete / not used]

Visual Studio version: [complete]

Platform Toolset: v145 · Language: C++17 · Configuration: Debug · Platform: x64

---

## How to use this evidence record

Complete this file **while you work through the lab**.

Keep your answers short. One or two sentences are enough unless the question asks for console output.

You do **not** need to:

- invent extra tests;
- create a separate testing framework;
- use `assert`;
- take screenshots for every step; or
- write a long report.

When the lab gives you an expected console result, run your program and compare what you see with that result. If something does not match, fix the code before moving on.

If your lecturer accepts another accessible format, you may provide the same evidence as typed notes or an agreed equivalent.

---

## 01 · Project setup

Create the Visual Studio project from scratch before completing this section.

**Project name:**

[complete]

**Files currently in the project:**

- [ ] `Main.cpp`
- [ ] `TrainingBot.h`
- [ ] `TrainingBot.cpp`

**Build settings checked:**

- [ ] Platform Toolset `v145`
- [ ] C++ Language Standard `ISO C++17`
- [ ] Warning Level `/W4`
- [ ] `Debug`
- [ ] `x64`

**First successful console output:**

```text
Training bot lab
```

**Did the starter project build and run successfully?**

[yes / no]

If no, briefly record the problem you fixed:

[complete / not applicable]

---

## 02 · First class and first object

After creating `TrainingBot.h` and `TrainingBot.cpp`, the program should create one `TrainingBot` object and print its starting health.

**Expected health before running:**

[complete]

**Actual console output:**

```text
[copy the relevant output here]
```

**Complete this sentence:**

`TrainingBot` is the ____________________, while `bot` is an ____________________ created from it.

**Why is `m_health` private?**

[one sentence]

**Status:**

[not started / working / complete]

---

## 03 · Challenge 1 — damage

Your `takeDamage(int t_amount)` function should reduce health without allowing it to become negative.

### Normal damage

The bot starts at 100 health and takes 25 damage.

**My prediction before running:**

Health will be: [complete]

**Actual health:**

[complete]

### Large damage

Temporarily change the damage amount to 500.

**My prediction before running:**

Health will be: [complete]

**Actual health:**

[complete]

**Why should the result be `0` rather than a negative number?**

[one sentence]

Return the damage amount to `25` before continuing.

**Status:**

[not started / working / complete]

---

## 04 · Challenge 2 — `isAlive()`

The `isAlive()` function should return `true` when health is greater than 0 and `false` when health is 0.

### After 25 damage

**Expected result:**

```text
Alive: true
```

**Actual result:**

```text
[complete]
```

### After heavy damage

**Expected result:**

```text
Alive now: false
```

**Actual result:**

```text
[complete]
```

**Why is `isAlive()` declared with `const`?**

[one sentence]

**Status:**

[not started / working / complete]

---

## 05 · Constructors

The lab uses two ways to create a `TrainingBot`:

```cpp
TrainingBot firstBot{};
TrainingBot secondBot{40};
```

**Starting health of `firstBot`:**

[complete]

**Starting health of `secondBot`:**

[complete]

**What does this part of the constructor do?**

```cpp
: m_health{t_health}
```

[one sentence]

**Status:**

[not started / working / complete]

---

## 06 · Challenge 3 — two separate objects

For this check, use:

```cpp
TrainingBot firstBot{};
TrainingBot secondBot{40};

firstBot.takeDamage(25);
secondBot.takeDamage(10);
```

### First run

**My prediction before running:**

- `firstBot` health: [complete]
- `secondBot` health: [complete]

**Actual values:**

- `firstBot` health: [complete]
- `secondBot` health: [complete]

### Small prediction check

Temporarily change:

```cpp
secondBot.takeDamage(10);
```

to:

```cpp
secondBot.takeDamage(50);
```

Before running, predict the values.

**Prediction:**

- `firstBot` health: [complete]
- `secondBot` health: [complete]

**Actual values:**

- `firstBot` health: [complete]
- `secondBot` health: [complete]

Restore the damage amount to `10` afterwards.

**What does this experiment show about two objects created from the same class?**

[one or two sentences]

**Status:**

[not started / working / complete]

---

## 07 · Final program check

Run the final version of the program.

Your console should match:

```text
Training bot lab

First bot
Starting health: 100
After 25 damage: 75
Alive: true

Second bot
Starting health: 40
After 10 damage: 30
Alive: true

Heavy damage
Second bot health: 0
Second bot alive: false
```

**Paste your final console output below:**

```text
[copy your final output here]
```

**Does your output match the lab?**

[yes / no]

If no, briefly describe the remaining difference:

[complete / not applicable]

---

## Short understanding check

Answer each question in one sentence.

**1. What is the difference between `TrainingBot` and `firstBot`?**

[complete]

**2. Why is `m_health` private?**

[complete]

**3. Why are `health()` and `isAlive()` `const` member functions?**

[complete]

**4. What does the member initialiser list in `TrainingBot(int t_health)` do?**

[complete]

---

## One problem I fixed

You only need to complete this section if you encountered a real problem.

**What went wrong?**

[complete / no problem recorded]

**What did I change?**

[complete / not applicable]

**What happened after rebuilding?**

[complete / not applicable]

Do not invent an error if you did not encounter one.

---

## Optional stretch · `reset()`

Complete this section only if you attempted the optional stretch task.

**Did you add `reset()`?**

[yes / no / not attempted]

**Expected output after reset:**

```text
After reset: 100
```

**Actual output:**

```text
[complete / not attempted]
```

**What does `reset()` change?**

[one sentence / not attempted]

---

## Final checklist

- [ ] I created the solution and project from scratch.
- [ ] `Main.cpp`, `TrainingBot.h` and `TrainingBot.cpp` are in the project.
- [ ] The project builds using C++17, `/W4`, Debug and x64.
- [ ] `m_health` is private.
- [ ] `takeDamage()` does not allow health to become negative.
- [ ] `health()` is `const`.
- [ ] `isAlive()` is `const`.
- [ ] The default constructor starts a bot at 100 health.
- [ ] `TrainingBot(int)` creates a bot with the supplied starting health.
- [ ] Two `TrainingBot` objects keep separate health values.
- [ ] My final console output matches the published output.
- [ ] Any temporary changes used for prediction checks have been restored.
- [ ] The final project builds successfully.

---

## Final note

One class concept I can now explain without copying the lab:

[complete]
