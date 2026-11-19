#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Prediction functions
void validate(double amount) {
    if (amount < 0) throw std::invalid_argument("negative");
    if (amount > 1e6) throw std::out_of_range("too large");
    std::cout << "ok ";
}

void process(double amount) {
    try {
        validate(amount);
    } catch (const std::out_of_range& e) {
        std::cout << "[log " << e.what() << "] ";
        throw;
    }
}

// Complete the code classes
class ClaimError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

double approve(double billed, double cover) {
    // TODO 1: Throw std::invalid_argument("negative amount") if billed or cover is negative;
    // throw ClaimError("exceeds cover") if billed > cover; otherwise return billed
    if (billed < 0 || cover < 0) {
        throw std::invalid_argument("negative amount");
    }
    if (billed > cover) {
        throw ClaimError("exceeds cover");
    }
    return billed;
}

double settle(double billed, double cover) {
    try {
        return approve(billed, cover);
    } catch (const ClaimError& e) {
        // TODO 2: Print "audit: " followed by the message, then rethrow the SAME exception
        std::cout << "audit: " << e.what() << '\n';
        throw; // Preserves dynamic exception type without slicing!
    }
}

int main() {
    std::cout << "=== Assignment 5 - Task B2: Engineer Error Conditions ===\n\n";

    // 1. Official Complete the Code execution
    std::cout << "1. Official Complete the Code Output:\n";
    double cases[][2] = {{40000, 50000}, {60000, 50000}, {-1, 50000}};
    for (auto& c : cases) {
        try {
            double paid = settle(c[0], c[1]);
            std::cout << "approved " << paid << '\n';
        } catch (const ClaimError& e) {
            std::cout << "claim rejected: " << e.what() << '\n';
        } catch (const std::exception& e) {
            std::cout << "error: " << e.what() << '\n';
        }
    }

    // 2. Predict the Output Verification
    std::cout << "\n2. Predict the Output Verification:\n";
    std::cout << "Actual execution:   ";
    for (double a : {100.0, -5.0, 2e6}) {
        try {
            process(a);
            std::cout << "done ";
        } catch (const std::exception& e) {
            std::cout << "caught " << e.what() << ' ';
        }
    }
    std::cout << '\n';
    std::cout << "Expected output:   ok done caught negative [log too large] caught too large \n";

    // 3. Stress Testing: Non-numeric parsing and bad_alloc simulation
    std::cout << "\n3. Additional Engineered Exceptions:\n";
    try {
        std::cout << "   Parsing invalid numeric bill string \"Rs-FortyThousand\"...\n";
        double val = std::stod("Rs-FortyThousand");
        std::cout << "   Parsed: " << val << '\n';
    } catch (const std::invalid_argument& ex) {
        std::cout << "   std::stod properly caught: " << ex.what() << '\n';
    }

    try {
        std::cout << "   Testing bad_alloc memory exhaustion safety...\n";
        size_t huge = static_cast<size_t>(-1) / 4;
        volatile char* p = new char[huge];
        delete[] p;
    } catch (const std::bad_alloc& ex) {
        std::cout << "   std::bad_alloc gracefully handled: " << ex.what() << '\n';
    }

    return 0;
}
