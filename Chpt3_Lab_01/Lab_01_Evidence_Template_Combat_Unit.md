# Chapter 3 · Practical Lab 1 · Evidence
## Combat unit inheritance console

Name or student identifier: c00324085

Date (YYYY-MM-DD): 2026/10/23

Repository URL, if used: [complete / not used]

Visual Studio version: V2026

Platform Toolset: **v145** · Language: **C++17** · Build: **Debug / x64** · Warning level: **/W4**

---

## How to use this record

Write short answers as you work through the practical. Use the **expected console output already printed in the lab**; you do not have to create separate test programs, write `assert` statements, or take a screenshot after every line. A short copied transcript or a text-based account is sufficient.

If a result differs, fix your source code and record the corrected result. Do not claim that an unrun or unsuccessful check passed.

## 01 · Project created from scratch

**Project and solution name:** CombatUnitInheritanceLab

Files present:

- [ ] `Main.cpp`
- [ ] `CombatUnit.h`
- [ ] `CombatUnit.cpp`
- [ ] `Archer.h`
- [ ] `Archer.cpp`

- [ ] I selected v145, ISO C++17, `/W4`, and Debug/x64.
- [ ] The first program built and printed `Combat unit inheritance lab`.

**If the first build needed a repair, what did you fix?**

no repair required
## 02 · CombatUnit base

What health did you give the first CombatUnit? 60

What did `attackPower()` return? 0

**Predict before running:** what should happen when the inner block ends?

When the inner block ends, guard goes out of scope and its destructor runs automatically thus printing - CombatUnit

**What actually appeared in your console?**

```text
Base unit
CombatUnit
Health: 60
Attack: 0
- CombatUnit
```

**Why is `m_health` private rather than directly editable from `main()`?**

Outside code can only read or change it through the class's public interface, so the class controls its own data

## 03 · Archer inheritance

**Predict before running:** write the order of the two constructor messages and the two destructor messages.

```text
  + CombatUnit
  + Archer
  - Archer
  - CombatUnit
```

**Actual order:**

```text
  CombatUnit
  + Archer
  - Archer
  - CombatUnit
```

**Starting health:** 80

**Archer attack power:** 12

**Why must the Archer constructor initialise `CombatUnit{t_health}` before its own body runs?**

the base part must exost before the derived part. CombatUnit doesn't have a default constructor meaning the archer constructor has no supply to the health value and the base is built before the Archer's own members and constructor body.

**Can Archer directly access CombatUnit’s private `m_health`? Why?**

Nop its private, archer uses the public health() instead

## 04 · Copy or view?

Before running, predict the five attack results.

| Expression | Prediction | Observed |
|---|---|---|
| `archer.attackPower()` | 12 | 12 |
| `baseCopy.attackPower()` | 0 | 0 |
| `baseView.attackPower()` | 0 | 0 |
| `pBase->attackPower()` | 0 | 0 |
| `archer.attackPower()` again | 12 | 12 |

**Which declaration makes a new independent base object?**

CombatUnit baseCopy{archer};

**Which declarations are only views of the original Archer?**

CombatUnit const& baseView{archer}; and CombatUnit const* pBase{&archer};

**Why does a base reference produce the base attack result even though it still refers to the Archer?**

it still refers to the whole Archer. attackPower is non-virtual so the compiler picks the function from the declared type of expression (CombatUnit) not from the actual object

**Why does the copied CombatUnit produce a destructor message without printing another parameterised constructor message?**

It was made by copy constructor, which doesnt print anything

## 05 · Known-object conversion

Identify the complete object that `pUnit` points into: Archer archer{75. 9}

**Expected base health:** 75

**Expected recovered Archer attack:** 9

**Observed values:** Base health: 75, Recovered attack: 9

**What fact makes this particular `static_cast<Archer*>` valid?**

assigned &archer to pUnit so I know it points to the base part of a real archer

**Should either pointer be deleted in this lab? Explain briefly.**

No both borrow access to the local archer, nothing was allocated with new and the archer is destroyed automatically after the closing brace

## 06 · Access investigation

**Before changing the inheritance keyword, predict which access rule will change.**

[one sentence]

**Did you temporarily try `protected` inheritance?** [yes / no]

**If attempted, what did the compiler reject?**

[one sentence / not attempted]

- [ ] I restored `class Archer : public CombatUnit`.
- [ ] The restored project builds successfully.

## Final console check

- [ ] All four sections match the expected output published in the lab.
- [ ] The program reports attack `12` directly, and `0` through the copied/base views.
- [ ] A known-object cast reports base health `75` and recovered attack `9`.
- [ ] The constructor/destructor messages appear in the expected order.
- [ ] I have removed any temporary build-only faults.

**Remaining difference from the published output, if any:**

[complete / none]

## One problem I fixed (only if applicable)

**What happened?** [complete / no issue encountered]

**What did I change?** [complete / not applicable]

**What happened after rebuilding?** [complete / not applicable]

Please do not invent a fault if none occurred.

## Optional stretch · VeteranArcher

**Attempted?** [yes / no]

**Predicted attack for arrow power 12 and bonus 3:** [complete / not attempted]

**Observed:** [complete / not attempted]

**Why did you write `Archer::attackPower()` inside the third-level function?**

[one sentence / not attempted]

## Final reflection

In one or two sentences, explain one difference between **inheritance**, **object slicing**, and **viewing an existing derived object through its base type**.

[complete]
