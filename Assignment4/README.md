# SIMATS ENGINEERING (SAVEETHA SCHOOL OF ENGINEERING)
## Department of Artificial Intelligence and Machine Learning
### ASSIGNMENT 4 - CO4: Designing Reusable Class Hierarchies

- **Student Name:** Mokshitha Kilari
- **Register Number:** 192525413
- **Section / Batch:** SLOT-D
- **Course Code & Title:** DSA0104 - Object Oriented Programming using C++
- **C++ Compiler & Version:** `g++ (Rev4, Built by MSYS2 project) 16.2.0` (C++17 Standard)
- **C++ Compilation Flags:** `g++ -std=c++17 -Wall -Wextra main.cpp -o main`
- **Java Version:** `Java SE 17 / 21 (JDK)`
- **Java Compilation Command:** `javac Main.java && java Task0X.Main`
- **GitHub Repository Link:** [https://github.com/MokshithaKilariSIMATS/DSA0104-192525413-Assignment4](https://github.com/MokshithaKilariSIMATS/DSA0104-192525413-Assignment4)

---

## Repository Structure
```
DSA01-192525413-Assignment4/
├── README.md
├── Assignment4_Report_192525413.docx
├── Task01/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task02/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task03/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task04/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task05/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
└── Task06/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
```

---

## Summary of Results by Task

### Task 1: Class Design Review (Diagnose & Repair Duplicated Classes)
- **Concept:** Elimination of duplicate attributes/formulas across `Professor`, `LabAssistant`, `GuestFaculty` via abstract base `Staff` with polymorphic `pay()`.
- **Result Note:** Entire payroll executed in a single polymorphic container loop; open for extension without modifying base classes.
```terminal
[Professor] ID: 101 | Name: Dr. Anand Kumar | Monthly Pay: Rs 128600.00
[Lab Assistant] ID: 202 | Name: Bala Murugan | Monthly Pay: Rs 49700.00
[Guest Faculty] ID: 303 | Name: Chitra Ramesh | Monthly Pay: Rs 48000.00
Total Institutional Payroll: Rs 226300.00
```

### Task 2: From Requirement to Hierarchy (Diamond Problem Resolution)
- **Concept:** Hybrid inheritance in `TeachingAssistant` inheriting from `Student` and `Staff`, resolved using `virtual public Person`.
- **Result Note:** Single `Person` sub-object created; verified Predict the Output sequence `Person Student Staff TA`.
```terminal
[CONSTRUCT] Person (Kavya) -> Student -> Staff -> TeachingAssistant
ID: 101 | Name: Kavya | Phone: 9876543210 | Prog: AI & ML | CGPA: 9.4 | Dept: CSE | Salary: Rs 25000
Predict output: Person Student Staff TA
```

### Task 3: Constructors in Derived Classes and Member Classes
- **Concept:** Member initializer lists initializing base class (`Person`), primitive fields (`regNo`), and member composition objects (`Address home`).
- **Result Note:** Verified exact construction/destruction order; matched expected output `192311001 Kavya (19) Salem-636001`.
```terminal
192311001 Kavya (19) Salem-636001
Predict output: Vehicle Engine Car | ~Car ~Engine ~Vehicle
```

### Task 4: Pointers to Derived Classes: Forensics
- **Concept:** Forensics on non-virtual methods, missing virtual destructors causing memory leaks, and object slicing.
- **Result Note:** Adding `virtual` and virtual destructor resolved 800-byte heap leak; verified Predict the Output `3.5 4 3.5`.
```terminal
Account interest rate: 3.5%
Account interest rate: 4%
[~SeniorAccount] Releasing 100-element history array
[~Account] Base destructor invoked
Predict output: 3.5 4 3.5
```

### Task 5: Pointers to Objects and the `this` Pointer
- **Concept:** Four ways to access an object (name, pointer `->`, reference, dynamic pointer), method chaining with `return *this`, parameter disambiguation.
- **Result Note:** Official expected output `324.00` verified; highest total cart found via array-of-pointers search.
```terminal
324.00
Direct: Rs 95.00 | Pointer: Rs 95.00 | Reference: Rs 95.00 | Heap: Rs 225.00
Highest Cart Total: Rs 405.00
```

### Task 6: Vehicle Rental Fleet (Design Challenge)
- **Concept:** Abstract base `Vehicle` with polymorphic `computeRental(days, lateDays)`. Derived: `Bicycle`, `TwoWheeler`, `Car`, `ElectricCar`.
- **Result Note:** Extended with `ElectricBus` with zero modifications to existing classes; full fleet rental processed cleanly.
```terminal
[Bicycle                  ] Reg: TN-01-BK-1001   | Total Charge: Rs 630.00
[Two-Wheeler              ] Reg: TN-02-TW-2002   | Total Charge: Rs 2075.00
[Petrol/Diesel Car        ] Reg: TN-03-CR-3003   | Total Charge: Rs 10800.00
[Electric Car             ] Reg: TN-04-EC-4004   | Total Charge: Rs 11832.00
[Electric Commercial Bus  ] Reg: TN-05-EB-5005   | Total Charge: Rs 44000.00
```
