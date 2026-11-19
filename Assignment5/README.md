# SIMATS ENGINEERING (SAVEETHA SCHOOL OF ENGINEERING)
## Department of Artificial Intelligence and Machine Learning
### ASSIGNMENT 5 - CO5: Reliable Software with Runtime Polymorphism and Exceptions

- **Student Name:** Mokshitha Kilari
- **Register Number:** 192525413
- **Section / Batch:** SLOT-D
- **Course Code & Title:** DSA0104 - Object Oriented Programming using C++
- **C++ Compiler & Version:** `g++ (Rev4, Built by MSYS2 project) 16.2.0` (C++17 Standard)
- **C++ Compilation Flags:** `g++ -std=c++17 -Wall -Wextra main.cpp -o main`
- **Java Version:** `Java SE 17 / 21 (JDK)`
- **Java Compilation Command:** `javac Main.java && java Task0X.Main`
- **GitHub Repository Link:** [https://github.com/MokshithaKilariSIMATS/DSA0104-192525413-Assignment5](https://github.com/MokshithaKilariSIMATS/DSA0104-192525413-Assignment5)

---

## Repository Structure
```
DSA01-192525413-Assignment5/
├── README.md
├── Assignment5_Report_192525413.docx
├── Task01/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task02/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task03/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
└── Task04/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
```

---

## Summary of Results by Task

### Task B1: Implement and Validate Polymorphic Billing
- **Concept:** Abstract base `Bill` with pure virtual `total()`, virtual `type()`, derived `OutPatient` and `InPatient`, dynamic dispatch and virtual destructors.
- **Result Note:** Output perfectly matches expected specification; removing `virtual` causes compile failure or static dispatch loss.
```terminal
OP Ravi: 1700
IP Meena: 47500
Total 49200
```

### Task B2: Engineer Error Conditions & Rethrowing
- **Concept:** Custom exception hierarchy `ClaimError : public std::runtime_error`, rethrowing the exact exception via `throw;` to preserve dynamic type.
- **Result Note:** Trapped negative claims, exceeded coverage, invalid numeric conversions (`std::stod`), and `bad_alloc` safely.
```terminal
approved 40000
audit: exceeds cover
claim rejected: exceeds cover
error: negative amount
Predict output: ok done caught negative [log too large] caught too large
```

### Task B3: Virtual Functions vs Switch vs Exceptions (The Cost Benchmark)
- **Concept:** Quantitative evaluation of virtual call overhead vs `switch` statement on small to massive datasets (1,000 to 10,000,000 items), and return code vs exception latency across error frequencies (0%, 1%, 50%).
- **Result Note:** Switch and virtual calls exhibit identical O(n) asymptotic scaling. Exceptions cost ~2.9 ms at 0% error rate but scale to 2.54 s at 50% error rate due to stack unwinding table overhead.
```terminal
B3.1 Small Data: Virtual = Rs 282500.00 | Switch = Rs 282500.00 (EXACT MATCH)
B3.2 Scalability (10M bills): Switch = 113.2 ms | Virtual = 71.6 ms
B3.3 Cost of Exceptions (1M claims):
     - Error Rate  0%: Return Code = 0 us | Exceptions = 2980 us
     - Error Rate  1%: Return Code = 0 us | Exceptions = 64770 us
     - Error Rate 50%: Return Code = 0 us | Exceptions = 2542360 us
```

### Task B4: Final Practical Extension & Production Decision
- **Concept:** Adding new `DayCareSurgeryBill` and `CorporateTieup` payer without modifying any existing class; verified RAII safety and clean leak-free memory.
- **Result Note:** 100% adherence to Open/Closed Principle; polymorphic architecture selected as superior choice for multi-hospital production scaling.
```terminal
[OP] Patient: Ravi       | Total: Rs 1700.00
[IP] Patient: Meena      | Total: Rs 47500.00
[DayCare] Patient: Suresh | Total: Rs 25500.00
Corporate Tie-Up (Tata Consultancy Services): Full coverage verified!
```
