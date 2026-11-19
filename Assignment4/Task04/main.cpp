#include <iostream>
#include <vector>
#include <memory>

// Prediction struct code from assignment sheet
struct PredAccount {
    double rate() const { return 3.5; }
    virtual double vrate() const { return 3.5; }
    virtual ~PredAccount() = default;
};

struct PredSeniorAccount : PredAccount {
    double rate() const { return 4.0; }
    double vrate() const override { return 4.0; }
};

// --- Repaired Bank Account Model ---
class Account {
public:
    virtual ~Account() {
        std::cout << "[~Account] Base destructor invoked\n";
    }
    virtual double rate() const { return 3.5; }
};

class SeniorAccount : public Account {
private:
    double* history;

public:
    SeniorAccount() : history(new double[100]) {
        for (int i = 0; i < 100; ++i) history[i] = 0.0;
    }
    ~SeniorAccount() override {
        std::cout << "[~SeniorAccount] Releasing 100-element history array\n";
        delete[] history;
    }
    double rate() const override { return 4.0; }
};

int main() {
    std::cout << "=== Assignment 4 - Task 4: Pointers to Derived Classes Forensics ===\n\n";

    // 1. Predict the Output Verification
    std::cout << "1. Predict the Output Verification:\n";
    {
        PredSeniorAccount s;
        PredAccount* p = &s;
        PredAccount copy = s;
        std::cout << "   Actual execution:   " << p->rate() << ' ' << p->vrate() << ' ' << copy.vrate() << '\n';
        std::cout << "   Expected output:   3.5 4 3.5\n";
    }

    // 2. Repaired Polymorphic Forensics Execution
    std::cout << "\n2. Repaired Polymorphic Execution (Virtual Functions & Virtual Destructor):\n";
    Account* accounts[2] = { new Account, new SeniorAccount };

    for (Account* a : accounts) {
        std::cout << "   Account interest rate: " << a->rate() << "%\n";
    }

    std::cout << "\n   Safely deleting accounts through base-class pointers:\n";
    for (Account* a : accounts) {
        delete a;
    }

    return 0;
}
