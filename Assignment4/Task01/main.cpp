#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

// Base class eliminating duplicated fields and providing polymorphic interface
class Staff {
protected:
    std::string name;
    int id;

public:
    Staff(const std::string& n, int i) : name(n), id(i) {}
    virtual ~Staff() = default;

    virtual double pay() const = 0; // Pure virtual function enforcing override
    virtual std::string getRole() const = 0;

    void display() const {
        std::cout << "[" << getRole() << "] ID: " << id << " | Name: " << name
                  << " | Monthly Pay: Rs " << std::fixed << std::setprecision(2) << pay() << '\n';
    }
};

// Professor: receives basic + DA (42%) + research allowance
class Professor : public Staff {
private:
    double basic;
    double daPercent;
    double researchAllowance;

public:
    Professor(const std::string& n, int i, double b, double r, double da = 0.42)
        : Staff(n, i), basic(b), daPercent(da), researchAllowance(r) {}

    double pay() const override {
        return basic + (basic * daPercent) + researchAllowance;
    }

    std::string getRole() const override { return "Professor"; }
};

// Lab Assistant: receives basic + DA (42%)
class LabAssistant : public Staff {
private:
    double basic;
    double daPercent;

public:
    LabAssistant(const std::string& n, int i, double b, double da = 0.42)
        : Staff(n, i), basic(b), daPercent(da) {}

    double pay() const override {
        return basic + (basic * daPercent);
    }

    std::string getRole() const override { return "Lab Assistant"; }
};

// Guest Faculty: receives hourly pay (hours * rate)
class GuestFaculty : public Staff {
private:
    double hours;
    double rate;

public:
    GuestFaculty(const std::string& n, int i, double h, double r)
        : Staff(n, i), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }

    std::string getRole() const override { return "Guest Faculty"; }
};

int main() {
    std::cout << "=== Assignment 4 - Task 1: Class Design Review & Hierarchy Refactoring ===\n\n";

    // Polymorphic processing: all staff handled uniformly in a single loop
    std::vector<std::unique_ptr<Staff>> staffMembers;
    staffMembers.push_back(std::make_unique<Professor>("Dr. Anand Kumar", 101, 80000.0, 15000.0));
    staffMembers.push_back(std::make_unique<LabAssistant>("Bala Murugan", 202, 35000.0));
    staffMembers.push_back(std::make_unique<GuestFaculty>("Chitra Ramesh", 303, 40.0, 1200.0));

    double totalPayroll = 0.0;
    std::cout << "Unified Payroll Processing:\n";
    for (const auto& member : staffMembers) {
        member->display();
        totalPayroll += member->pay();
    }

    std::cout << "\nTotal Institutional Payroll: Rs " << totalPayroll << '\n';
    return 0;
}
