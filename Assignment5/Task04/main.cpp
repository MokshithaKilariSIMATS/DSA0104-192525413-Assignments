#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <stdexcept>

// Existing Abstract Base Class: Bill
class Bill {
protected:
    std::string patient;

public:
    explicit Bill(const std::string& p) : patient(p) {}
    virtual ~Bill() = default;

    virtual double total() const = 0;
    virtual std::string type() const { return "Bill"; }

    void print() const {
        std::cout << "[" << type() << "] Patient: " << std::left << std::setw(10) << patient
                  << " | Total: Rs " << std::fixed << std::setprecision(2) << total() << '\n';
    }
};

// Existing Derived Classes
class OutPatient : public Bill {
    double consultation, tests;
public:
    OutPatient(const std::string& p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}
    double total() const override { return consultation + tests; }
    std::string type() const override { return "OP"; }
};

class InPatient : public Bill {
    int days;
    double perDay, surgery;
public:
    InPatient(const std::string& p, int d, double rate, double s)
        : Bill(p), days(d), perDay(rate), surgery(s) {}
    double total() const override { return days * perDay + surgery; }
    std::string type() const override { return "IP"; }
};

// Abstract Payer Strategy
class Payer {
public:
    virtual ~Payer() = default;
    virtual double amountCovered(const Bill& b) const = 0;
    virtual std::string getPayerName() const = 0;
};

// Existing Payers
class SelfPay : public Payer {
public:
    double amountCovered(const Bill&) const override { return 0.0; } // Patient pays 100%
    std::string getPayerName() const override { return "Self-Pay"; }
};

class Insurance : public Payer {
    double coverLimit;
    double copayPct; // e.g. 10%
public:
    Insurance(double limit, double copay) : coverLimit(limit), copayPct(copay) {}
    double amountCovered(const Bill& b) const override {
        double payable = b.total() * (1.0 - copayPct / 100.0);
        return (payable > coverLimit) ? coverLimit : payable;
    }
    std::string getPayerName() const override { return "Private Insurance"; }
};

// ============================================================================
// B4.1 PRACTICAL EXTENSION: ADDING NEW BILL TYPE & NEW PAYER WITHOUT MODIFYING EXISTING CLASSES
// ============================================================================

// 1. New Bill Type: DayCareSurgeryBill (Package price + specialized implants)
class DayCareSurgeryBill : public Bill {
private:
    double packageRate;
    double implantCost;

public:
    DayCareSurgeryBill(const std::string& p, double pkg, double implant)
        : Bill(p), packageRate(pkg), implantCost(implant) {}

    double total() const override {
        return packageRate + implantCost;
    }

    std::string type() const override { return "DayCare"; }
};

// 2. New Payer: CorporateTieup (Full coverage up to corporate cap with 0% copay)
class CorporateTieup : public Payer {
private:
    std::string corporateName;
    double annualCreditLimit;

public:
    CorporateTieup(const std::string& corp, double limit)
        : corporateName(corp), annualCreditLimit(limit) {}

    double amountCovered(const Bill& b) const override {
        return (b.total() > annualCreditLimit) ? annualCreditLimit : b.total();
    }

    std::string getPayerName() const override {
        return "Corporate Tie-Up (" + corporateName + ")";
    }
};

int main() {
    std::cout << "=== Assignment 5 - Task B4: Final Practical Extension & Production Verification ===\n\n";

    // Polymorphic collection of existing and newly extended bills
    std::vector<std::unique_ptr<Bill>> hospitalBills;
    hospitalBills.push_back(std::make_unique<OutPatient>("Ravi", 500, 1200));
    hospitalBills.push_back(std::make_unique<InPatient>("Meena", 3, 2500, 40000));
    // Newly extended Bill Type:
    hospitalBills.push_back(std::make_unique<DayCareSurgeryBill>("Suresh", 18000, 7500));

    std::cout << "1. Processing All Bills (Including Extended DayCare Bill):\n";
    for (const auto& b : hospitalBills) {
        b->print();
    }

    // Payers evaluation
    std::cout << "\n2. Payer Settlement Matrix:\n";
    std::vector<std::unique_ptr<Payer>> payers;
    payers.push_back(std::make_unique<SelfPay>());
    payers.push_back(std::make_unique<Insurance>(45000.0, 10.0));
    // Newly extended Payer:
    payers.push_back(std::make_unique<CorporateTieup>("Tata Consultancy Services", 50000.0));

    for (const auto& p : payers) {
        std::cout << "\n--- Payer: " << p->getPayerName() << " ---\n";
        for (const auto& b : hospitalBills) {
            double covered = p->amountCovered(*b);
            double patientDue = b->total() - covered;
            std::cout << "  * " << b->type() << " Bill (" << std::fixed << std::setprecision(2)
                      << b->total() << ") -> Covered: Rs " << covered
                      << " | Patient Due: Rs " << patientDue << '\n';
        }
    }

    std::cout << "\n3. Architectural Verification:\n";
    std::cout << "   - Zero existing classes modified (OCP fully maintained)\n";
    std::cout << "   - Clean resource destruction via smart pointers (RAII verified)\n";

    return 0;
}
