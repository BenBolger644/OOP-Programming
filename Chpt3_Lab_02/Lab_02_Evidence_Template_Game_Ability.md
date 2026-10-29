# Chapter 03 · Practical Lab 02 · Evidence
## Game ability virtual console

Student identifier: c00324085

Date (YYYY-MM-DD): 2026-10-29

Visual Studio version: v2026

Platform Toolset: v145 · ISO C++17 · /W4 · Debug / x64

Repository URL, if used: https://github.com/BenBolger644/OOP-Programming

---

## How to complete this record

Fill this in while you work through the practical. Short answers are sufficient. You do **not** need to invent new tests, create a testing framework, or take screenshots of every step. The practical already gives you the expected console output.

For each prediction, make your prediction **before** running the code. When the program behaves differently, fix the code or explain your revised understanding. Record only genuine problems; do not manufacture a compiler error to fill an evidence box.

---

## 01 · Project setup

Project name: GameAbilityVirtualLab

Check the files you created from scratch:

- [ ] `Main.cpp`
- [ ] `Abilities.h`
- [ ] `Abilities.cpp`
- [ ] `Runner.h`
- [ ] `Runner.cpp`

- [ ] v145 selected
- [ ] ISO C++17 selected
- [ ] `/W4` selected
- [ ] Debug / x64 selected
- [ ] The starter program built and printed `Game ability lab`

One project problem I solved, if applicable: none

## 02 · Non-virtual calls

The first version of `GameAbility::activate()` is **not virtual**. A `GameAbility const&` refers to a `ShieldAbility` object.

My prediction for the three calls:

- Direct ShieldAbility: Shield power: 20
- GameAbility base reference: Generic ability:
- Direct HealAbility: Healing points: 15

Actual output:
```text
Non-Virtual check
Direct: Shield Power: 20
Base View: Generic Ability
Second Type: Healing Points: 15
```

Why does the base reference use that function body? activate() isn't virtual, so the compiler picks the function from the reference's declared type ( Game Ability ), even though the object is a ShieldAbility

## 03 · Virtual calls and override

After adding `virtual` in `GameAbility` and `override` to both concrete classes:

Expected base-reference result: Shield power: 20

Actual base-reference result: Shield Power: 20

Which part of this declaration must match the base to make the override valid?

```cpp
void activate() const override;
```

the whole signature including the const after the parameter list

If you attempted the build-only `const` mismatch: first useful diagnostic or concise explanation: Not attempted

- [ ] The original matching declaration has been restored.

## 04 · Abstract GameAbility

What is the purpose of the following declaration?

```cpp
virtual void activate() const = 0;
```

it makes activate() pure virtual, so GameAbility is abstract and every class must supply its own activate()

Which of the following may be a complete object? Record the explanation.

- `GameAbility generic{10};` — rejected because its abstract and has a pure virtual function
- `ShieldAbility shield{20};` — allowed because it overrides activate(), so its a complete concrete class

- [ ] The temporary abstract-object build-only experiment has been removed.
- [ ] The remaining valid program builds.

## 05 · Virtual destructor and ownership

One `HealAbility{7}` is created with `new` and owned through `GameAbility*`.

Expected destructor messages after the matching `delete`:

```text
- HealAbility
- GameAbility
```

Observed two-line destructor trace:

```text
- HealAbility
- GameAbility
```

Why does the base destructor need to be virtual for this deletion? delete through a GameAbility* runs the most-derived destructor first. With a non-virtual basae destructor this is undefined behaviour

Why should you **not** delete a pointer that merely refers to a local `ShieldAbility`? it was never allocated with new, the pointer only borrows it, and the local object is destroyed at the end of scope.

## 06 · Generic runner

Your runner should **not** name the concrete classes. It works through the GameAbility interface.

Given the three slots `&shield`, `nullptr`, `&heal`:

Predicted number of activations: 2

Actual number: 2

Were shield and heal's stored powers unchanged? yes
Boundary calls:

| Call | Predicted | Actual |
|---|---|---|
| `activateReady(nullptr, 0)` | 0 | 0 |
| `activateReady(nullptr, 1)` | -1 | -1 |

Why must the runner check a slot for `nullptr` before calling `power()` or `activate()`? calling power() or activate() through a null pointer is undefined behaviour

Why can a third concrete ability join the array without a new branch in `Runner.cpp`? the runner calls the virtual activate() through the GameAbility interface, so it never needs to know the concrete type

## Final output

Paste your final console transcript, or provide an agreed accessible text equivalent:

```text

Virtual callsGame ability lab
Direct: Shield Power: 20
Base view: Shield Power: 20
Second type: Healing Points: 15
Ability Runner
Shield Power: 20
Healing Points: 15
Activated: 2
Powers: 20 15
Boundary checks
Empty: 0
Missing Array: -1
Owned action
Healing Points: 7
- HealAbility
- GameAbility
Leaving Scope
- HealAbility
- GameAbility
- GameAbility
```

Does it match the practical's published final output? ywa

If no, record the remaining difference: not applicable

## One real problem I fixed (optional)

What happened? none

What changed? not applicable

What happened after rebuilding? not applicable

## Optional stretch · DashAbility

- [ ] Not attempted
- [ ] Attempted: implemented `DashAbility` with `activate() const override`
- [ ] Runner works with DashAbility without edits to `Runner.cpp`

My extra output (if attempted): [complete / not attempted]

## Final checklist

- [ ] My project was created from an Empty Project.
- [ ] All five required files are present in the Visual Studio project.
- [ ] The program builds with v145, C++17, /W4, Debug / x64.
- [ ] The initial non-virtual result has been understood and recorded.
- [ ] `activate()` is virtual and then pure in the final base class.
- [ ] Both concrete `activate() const` declarations use `override` correctly.
- [ ] `GameAbility` cannot be instantiated as a complete object.
- [ ] The base destructor is virtual and has a matching definition.
- [ ] The owned dynamically allocated `HealAbility` is deleted exactly once.
- [ ] The runner skips invalid/null/inactive inputs according to the brief.
- [ ] Temporary deliberate compilation failures have been removed.
- [ ] The final console output matches the published example.

One concept I can now explain without looking at the code:
A base class reference only calls the derived version if the function is virtual. Without virtual the compiler uses the references declared type so the override and virtual destructors are what make base class interaces safe and free to use without problem
