# Session Ledger

A small C++ console utility that logs a handful of shift entries in a
single run, keeping a running entry count and running hour totals — including
a separate average for "long shifts" — using state that persists across
function calls without being exposed to the rest of the program.

Built as a learning project while working through
[learncpp.com](https://www.learncpp.com/), focused on consolidating
Chapter 7: scope, duration, and linkage — specifically how to hide mutable
state behind a function-only interface, and how to safely share constants
across multiple files without violating the one-definition rule. Earlier
fundamentals (functions, types, operators, validation) are used as
supporting scaffolding, not the focus.

## What it does

- Reads four shift-hour entries from the console, validating each before
  it's recorded
- Assigns each entry an auto-incrementing ID and keeps a running total of
  hours across the session, with no counter passed around manually
- Tracks a separate running total and average for "long shifts" (hours at
  or above a shared threshold)
- Prints a per-entry line as each one is logged, then a session summary at
  the end: total entries, total hours, long-shift average

## Project structure

```
main.cpp                    // program entry point, orchestrates the flow                   
io/                         
  io.h                      // reading entry hours, printing entries and summary
  io.cpp             
helpers/                    
  validate.h                // isEntryHoursValid() — a pure predicate, no side effects
  validate.cpp
  compare.h                 // epsilon-tolerant double comparisons (isLessOrEqual, isGreaterOrEqual)
consts/
  consts.h                  // inline constexpr thresholds shared across files
globals/
  globals.h                 // session state (id, totals) — hidden behind a function-only interface
  globals.cpp          
```

## Building

Requires a C++20-capable compiler.

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wsign-conversion -o app \
    main.cpp io/io.cpp helpers/validate.cpp globals/globals.cpp
```

Or open `Session Ledger.slnx` in Visual Studio.

## Running

```bash
./app
```

Example session:

```
Enter entry hours(0<hours<=12.0): 6.5
Enter entry hours(0<hours<=12.0): 9.0
Enter entry hours(0<hours<=12.0): 4.25
Enter entry hours(0<hours<=12.0): 2.0
Entry #1: 6.5 hours
Entry #2: 9 hours
Entry #3: 4.25 hours
Entry #4: 2 hours
--- Session Summary ---
Total entries: 4
Total hours: 21.75
Long-shift average: 9
```

## Notes

`Globals`'s session state (`sId`, `sTotal`, `sLongShiftTotal`,
`sLongShiftAmount`) is declared `static` inside `globals.cpp` and never
appears in `globals.h` — only functions are exposed, so no other file can
read or write that state except through `Globals::id()` and
`Globals::recordEntry()`. Shared thresholds in `consts.h` use `inline
constexpr` instead, which is the safe way to define true constants in a
header included by multiple translation units. Validation and state
mutation are deliberately kept separate: `isEntryHoursValid()` is a pure
check with no side effects, and `Globals::recordEntry()` is the one
explicit place where session state actually changes.