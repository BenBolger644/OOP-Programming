# Chapter 2 · Practical Lab 1 · Evidence
## Training bot status console

Name or student identifier: Benjamin Bolger C00324085

Date (YYYY-MM-DD): 06/10/2026

Repository URL, if used: https://github.com/BenBolger644/OOP-Programming

Visual Studio version: vs2026

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

TraingBotLab

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

yes

If no, briefly record the problem you fixed:

No Problem

---

## 02 · First class and first object

After creating `TrainingBot.h` and `TrainingBot.cpp`, the program should create one `TrainingBot` object and print its starting health.

**Expected health before running:**

Health will start at 100

**Actual console output:**

```text
starting health: 100
```

**Complete this sentence:**

`TrainingBot` is the class, while `bot` is an object created from it.

**Why is `m_health` private?**

Its private as it is not needed to be accessed directly, as a function will be created for that.

**Status:**

complete

---

## 03 · Challenge 1 — damage

Your `takeDamage(int t_amount)` function should reduce health without allowing it to become negative.

### Normal damage

The bot starts at 100 health and takes 25 damage.

**My prediction before running:**

Health will be: 75

**Actual health:**

75

### Large damage

Temporarily change the damage amount to 500.

**My prediction before running:**

Health will be: 0

**Actual health:**

0

**Why should the result be `0` rather than a negative number?**

Because we have written code that converts players health to 0 if damage is greater than current health

Return the damage amount to `25` before continuing.

**Status:**

Complete

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
Alive: true
```

### After heavy damage

**Expected result:**

```text
Alive now: false
```

**Actual result:**

```text
alive: false
```

**Why is `isAlive()` declared with `const`?**

the function only looks at the bot and not its actual health

**Status:**

complete

---

## 05 · Constructors

The lab uses two ways to create a `TrainingBot`:

```cpp
TrainingBot firstBot{};
TrainingBot secondBot{40};
```

**Starting health of `firstBot`:**

100

**Starting health of `secondBot`:**

40

**What does this part of the constructor do?**

```cpp
: m_health{t_health}
```

it initializes m_health with the value of t_health

**Status:**

complete

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

- `firstBot` health: 75
- `secondBot` health: 30

**Actual values:**

- `firstBot` health: 75
- `secondBot` health: 30

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

- `firstBot` health: 75
- `secondBot` health: 0

**Actual values:**

- `firstBot` health: 75
- `secondBot` health: 0

Restore the damage amount to `10` afterwards.

**What does this experiment show about two objects created from the same class?**

The two objects are from the same class but can have their own seperate variables values based on spawning conditions and actions taken to their specific objecct.

**Status:**

complete

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

**Does your output match the lab?**

yes

If no, briefly describe the remaining difference:

complete

---

## Short understanding check

Answer each question in one sentence.

**1. What is the difference between `TrainingBot` and `firstBot`?**

TrainingBot is the class while first bot is the object of the training bot

**2. Why is `m_health` private?**

Because its in the private section of the traingbot class as main.cpp shouldnt and doesnt need to access it directly.

**3. Why are `health()` and `isAlive()` `const` member functions?**

They are const because they do not need to change, and thus making the class easier to change around.

**4. What does the member initialiser list in `TrainingBot(int t_health)` do?**

Training bot has the original 100 health when using the default member, but trainingbot can be called with (int_health) to customize the spawn health if wished.

---

## One problem I fixed

You only need to complete this section if you encountered a real problem.

**What went wrong?**

No problem

**What did I change?**

No problem

**What happened after rebuilding?**

No problem

Do not invent an error if you did not encounter one.

---

## Optional stretch · `reset()`

Complete this section only if you attempted the optional stretch task.

**Did you add `reset()`?**

yes

**Expected output after reset:**

```text
After reset: 100
```

**Actual output:**

```text
after reset: 100
```

**What does `reset()` change?**

Reset simply changes the health back to its original

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

How consts work efficiently and effectively. I wasnt completely able to before this lab