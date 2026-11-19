# Assessment 1 – C++ Programming Repository

**Student Name:** Mokshitha Kilari  
**Register Number:** 192525413  
**Course:** C++ Programming  
**Compiler:** g++ 13 (C++17)  
**Standard:** C++17

## Exact compilation command

```bash
g++ -std=c++17 -Wall -Wextra -Wconversion -pedantic main.cpp -o program
```

## How to run

Open a terminal inside the required task folder and run:

```bash
g++ -std=c++17 -Wall -Wextra -Wconversion -pedantic main.cpp -o program
./program
```

On Windows PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra -Wconversion -pedantic main.cpp -o program.exe
.\program.exe
```

Task 8 accepts keyboard input and its supplied test input is stored in `input.txt`. The other tasks use fixed demonstration/test data based on the assessment requirements.

## Repository structure

Each task is isolated in its own folder and contains the C++ source, input/reference data, compiler evidence, actual program output, and an output screenshot.

```text
Assessment1_CPP_Repository/
├── README.md
├── Task01/
│   ├── main.cpp
│   ├── input.txt
│   ├── compile_output.txt
│   ├── output.txt
│   └── output_screenshot.png
├── Task02/
...
└── Task12/
    ├── main.cpp
    ├── input.txt
    ├── compile_output.txt
    ├── output.txt
    └── output_screenshot.png
```

## Task results

| Task | Result |
|---|---|
| Task 1 | Demonstrates `Passenger` and `SmartCard` objects and their responsibilities. |
| Task 2 | Demonstrates C++ keywords, identifiers, constants, operators and `enum class`. |
| Task 3 | Demonstrates suitable data types, exact paise representation and actual compiler type sizes/limits. |
| Task 4 | Demonstrates integer division, explicit floating-point conversion, character promotion and boolean/signed conversion behaviour. |
| Task 5 | Demonstrates operator precedence, increment operators, conditional operator, division/modulo and peak-hour logic. |
| Task 6 | Implements fare calculation and card validation using `switch`, `if`, loops and a conditional expression. |
| Task 7 | Compares procedural fare deduction with an encapsulated `SmartCard` class. |
| Task 8 | Demonstrates safe numeric input recovery and exact currency formatting. |
| Task 9 | Runs boundary-focused fare tests and reports PASS/FAIL results. |
| Task 10 | Compares network-scale totals, integer capacity and measured floating-point accumulation behaviour. |
| Task 11 | Demonstrates the recommended final design with central `FarePolicy`, private card balance and integer paise. |
| Task 12 | Implements Airport fare, weekend discount precedence and a two-zone `MonthlyPass`. |

## Evidence note

`output.txt` and `output_screenshot.png` were produced from the compiled programs in this repository. The screenshots show the actual captured execution output, not manually typed sample output.

The assessment specifies that actual compiler warnings, environment sizes and measured results should be recorded from execution. The `compile_output.txt` files preserve the compilation result for each task.
