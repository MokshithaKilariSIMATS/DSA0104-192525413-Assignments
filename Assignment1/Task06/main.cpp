#include <iostream>
#include <iomanip>
using namespace std;

enum class Zone { Inner, Middle, Outer };

long long fare(Zone z, bool peak) {
    long long base = 0;
    switch (z) {
        case Zone::Inner: base = 1000; break;
        case Zone::Middle: base = 2000; break;
        case Zone::Outer: base = 3000; break;
        default: return -1;
    }
    return peak ? base + base * 20 / 100 : base;
}

bool canTravel(long long balance, long long f) {
    return f >= 0 && balance >= f && balance - f >= 5000;
}

void money(long long p) {
    cout << "Rs " << p/100 << "." << setw(2) << setfill('0') << p%100
         << setfill(' ');
}

int main() {
    long long balance = 10000;
    struct Trip { Zone zone; int hour; };
    Trip trips[] = {{Zone::Inner,7},{Zone::Outer,17},{Zone::Middle,10}};

    cout << "Initial balance: Rs 100.00\n";
    for (const auto& t : trips) {
        bool peak = (t.hour >= 8 && t.hour < 10) ||
                    (t.hour >= 17 && t.hour < 20);
        long long f = fare(t.zone, peak);
        if (canTravel(balance, f)) {
            balance -= f;
            cout << "Accepted | Fare "; money(f);
            cout << " | Balance Rs " << balance/100 << "."
                 << setw(2) << setfill('0') << balance%100 << setfill(' ') << "\n";
        } else {
            cout << "Denied   | Balance unchanged\n";
        }
    }
}
