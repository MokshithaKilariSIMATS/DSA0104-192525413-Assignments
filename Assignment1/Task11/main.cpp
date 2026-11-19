#include <iostream>
#include <array>
#include <string>
using namespace std;

enum class Zone { Inner, Middle, Outer };

class FarePolicy {
    static constexpr array<long long,3> BASE = {1000,2000,3000};
public:
    static long long calculate(Zone zone, int hour) {
        if (hour < 0 || hour > 23) return -1;
        size_t i = static_cast<size_t>(zone);
        if (i >= BASE.size()) return -1;
        long long base = BASE[i];
        bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
        return peak ? base + base*20/100 : base;
    }
};

class SmartCard {
    long long balancePaise;
public:
    explicit SmartCard(long long initial) : balancePaise(initial) {}
    bool deduct(long long fare) {
        if (fare < 0 || balancePaise - fare < 5000) return false;
        balancePaise -= fare;
        return true;
    }
    long long balance() const { return balancePaise; }
};

int main() {
    SmartCard card(6000);
    cout << "Final design demonstration\n";
    cout << "Central fare policy : enabled\n";
    cout << "Private card balance: enabled\n";
    cout << "Currency storage    : integer paise\n";

    long long fare = FarePolicy::calculate(Zone::Inner, 8);
    cout << "Calculated peak fare: Rs " << fare/100 << "." << fare%100 << "\n";

    cout << "Trip result         : "
         << (card.deduct(fare) ? "Accepted" : "Denied") << "\n";
    cout << "Remaining balance   : Rs "
         << card.balance()/100 << "." << card.balance()%100 << "\n";
}
