#include <iostream>
#include <vector>
#include <chrono>
#include <memory>
#include <random>
#include <iomanip>

// (a) Polymorphic Design using Virtual Functions
class PolymorphicBill {
public:
    virtual ~PolymorphicBill() = default;
    virtual double total() const = 0;
};

class PolyOP : public PolymorphicBill {
    double consultation, tests;
public:
    PolyOP(double c, double t) : consultation(c), tests(t) {}
    double total() const override { return consultation + tests; }
};

class PolyIP : public PolymorphicBill {
    int days;
    double perDay, surgery;
public:
    PolyIP(int d, double r, double s) : days(d), perDay(r), surgery(s) {}
    double total() const override { return days * perDay + surgery; }
};

// (b) Single Struct with Enum Type and Switch Statement
enum class BillType { OP, IP };

struct StructBill {
    BillType type;
    double field1; // consultation or days
    double field2; // tests or perDay
    double field3; // surgery

    double total() const {
        switch (type) {
            case BillType::OP:
                return field1 + field2;
            case BillType::IP:
                return (field1 * field2) + field3;
            default:
                return 0.0;
        }
    }
};

// Validation comparison: Return code vs Exception
enum class Status { OK, INVALID_AMOUNT, EXCEEDS_COVER };

Status validateByReturnCode(double billed, double cover, double& outPaid) {
    if (billed < 0 || cover < 0) return Status::INVALID_AMOUNT;
    if (billed > cover) return Status::EXCEEDS_COVER;
    outPaid = billed;
    return Status::OK;
}

double validateByException(double billed, double cover) {
    if (billed < 0 || cover < 0) throw std::invalid_argument("negative");
    if (billed > cover) throw std::runtime_error("exceeds");
    return billed;
}

int main() {
    std::cout << "=== Assignment 5 - Task B3: Performance Benchmark & Trade-offs ===\n\n";

    // B3.1: Small Data Correctness Verification (10 Bills)
    std::vector<std::unique_ptr<PolymorphicBill>> poly10;
    std::vector<StructBill> struct10;

    for (int i = 0; i < 5; ++i) {
        poly10.push_back(std::make_unique<PolyOP>(500.0 + i * 100, 1200.0 + i * 50));
        struct10.push_back({BillType::OP, 500.0 + i * 100, 1200.0 + i * 50, 0.0});

        poly10.push_back(std::make_unique<PolyIP>(3 + i, 2500.0, 40000.0 + i * 1000));
        struct10.push_back({BillType::IP, static_cast<double>(3 + i), 2500.0, 40000.0 + i * 1000});
    }

    double sumPoly = 0.0;
    for (const auto& b : poly10) sumPoly += b->total();

    double sumStruct = 0.0;
    for (const auto& b : struct10) sumStruct += b.total();

    std::cout << "B3.1 Small Data (10 Bills) Verification:\n";
    std::cout << "  - Virtual Function Total: Rs " << std::fixed << std::setprecision(2) << sumPoly << '\n';
    std::cout << "  - Switch Statement Total: Rs " << sumStruct << '\n';
    std::cout << "  - Result: " << (sumPoly == sumStruct ? "EXACT MATCH (Verified)" : "MISMATCH") << "\n\n";

    // B3.2: Benchmark 1,000, 1,000,000, and 10,000,000 Bills
    std::cout << "B3.2 Scalability Benchmark (-O2 Optimization):\n";
    for (int count : {1000, 1000000, 10000000}) {
        std::vector<StructBill> sVec(count, {BillType::OP, 500.0, 1200.0, 0.0});
        std::vector<PolymorphicBill*> pVec(count);
        PolyOP sampleOP(500.0, 1200.0);
        for (int i = 0; i < count; ++i) pVec[i] = &sampleOP;

        // Time switch
        auto t1 = std::chrono::high_resolution_clock::now();
        volatile double totalS = 0.0;
        for (int i = 0; i < count; ++i) totalS = totalS + sVec[i].total();
        auto t2 = std::chrono::high_resolution_clock::now();
        auto durSwitch = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

        // Time virtual
        auto t3 = std::chrono::high_resolution_clock::now();
        volatile double totalP = 0.0;
        for (int i = 0; i < count; ++i) totalP = totalP + pVec[i]->total();
        auto t4 = std::chrono::high_resolution_clock::now();
        auto durPoly = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

        std::cout << "  [" << std::setw(8) << count << " Bills] Switch: "
                  << std::setw(7) << durSwitch << " us | Virtual: "
                  << std::setw(7) << durPoly << " us\n";
    }

    // B3.3: Cost of Exceptions vs Return Codes
    std::cout << "\nB3.3 Cost of Exceptions vs Return Codes (1,000,000 Claims):\n";
    const int N_CLAIMS = 1000000;
    for (int failurePercent : {0, 1, 50}) {
        auto startRC = std::chrono::high_resolution_clock::now();
        int validCountRC = 0;
        for (int i = 0; i < N_CLAIMS; ++i) {
            double billed = 40000.0;
            double cover = (i % 100 < failurePercent) ? 30000.0 : 50000.0;
            double paid = 0.0;
            if (validateByReturnCode(billed, cover, paid) == Status::OK) {
                ++validCountRC;
            }
        }
        auto endRC = std::chrono::high_resolution_clock::now();
        auto durRC = std::chrono::duration_cast<std::chrono::microseconds>(endRC - startRC).count();

        auto startEx = std::chrono::high_resolution_clock::now();
        int validCountEx = 0;
        for (int i = 0; i < N_CLAIMS; ++i) {
            double billed = 40000.0;
            double cover = (i % 100 < failurePercent) ? 30000.0 : 50000.0;
            try {
                validateByException(billed, cover);
                ++validCountEx;
            } catch (...) {
                // error handled
            }
        }
        auto endEx = std::chrono::high_resolution_clock::now();
        auto durEx = std::chrono::duration_cast<std::chrono::microseconds>(endEx - startEx).count();

        std::cout << "  - Error Rate " << std::setw(2) << failurePercent << "% : Return Code = "
                  << std::setw(6) << durRC << " us | Exceptions = "
                  << std::setw(8) << durEx << " us\n";
    }

    return 0;
}
