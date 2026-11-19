#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Cart {
    std::string items[10];
    double prices[10];
    int n = 0;
    double discount = 0; // percent

public:
    // TODO 1: add(): store the item and price if there is space, and return *this so that calls can be chained
    Cart& add(const std::string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }

    // TODO 2: setDiscount(): use this-> to tell the member apart from the parameter named discount, and return *this
    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;
        for (int i = 0; i < n; ++i) t += prices[i];
        return t * (100 - discount) / 100;
    }

    void printReceipt() const {
        std::cout << "Items in Cart (" << n << "):\n";
        for (int i = 0; i < n; ++i) {
            std::cout << "  - " << std::left << std::setw(12) << items[i] << " : Rs " << prices[i] << '\n';
        }
        std::cout << "Discount: " << discount << "% | Total: Rs "
                  << std::fixed << std::setprecision(2) << total() << '\n';
    }
};

int main() {
    std::cout << "=== Assignment 4 - Task 5: Pointers to Objects & the this Pointer ===\n\n";

    // 1. Official Assignment Complete the Code
    std::cout << "Official Complete the Code Output:\n";
    Cart c;
    c.add("Rice", 60).add("Dal", 120).setDiscount(10);
    Cart* p = &c; // pointer to an object
    p->add("Oil", 180);
    std::cout << std::fixed << std::setprecision(2) << p->total() << '\n';

    // 2. Demonstration of the Four Ways to Reach an Object
    std::cout << "\nDemonstration of the Four Ways to Reach a Cart Object:\n";
    // (a) Directly by name
    Cart cartA;
    cartA.add("Apple", 100).setDiscount(5);
    std::cout << "  (a) Directly by name total: Rs " << cartA.total() << '\n';

    // (b) Through a pointer with ->
    Cart* ptrA = &cartA;
    std::cout << "  (b) Through pointer (->) total: Rs " << ptrA->total() << '\n';

    // (c) Through a reference
    Cart& refA = cartA;
    std::cout << "  (c) Through reference (.) total: Rs " << refA.total() << '\n';

    // (d) Dynamically on heap with new/delete
    Cart* heapCart = new Cart();
    heapCart->add("Mango", 250).setDiscount(10);
    std::cout << "  (d) Through heap pointer (new/delete) total: Rs " << heapCart->total() << '\n';
    delete heapCart;

    // 3. Finding cart with highest total using array of pointers
    std::cout << "\nFinding Highest Total among Active Customer Carts:\n";
    Cart c1, c2, c3;
    c1.add("Sugar", 50);
    c2.add("Spices", 450).setDiscount(10); // 405
    c3.add("Flour", 200);

    Cart* activeCarts[3] = { &c1, &c2, &c3 };
    Cart* highestCart = activeCarts[0];
    for (int i = 1; i < 3; ++i) {
        if (activeCarts[i]->total() > highestCart->total()) {
            highestCart = activeCarts[i];
        }
    }
    std::cout << "  Highest Cart Total: Rs " << highestCart->total() << '\n';

    return 0;
}
