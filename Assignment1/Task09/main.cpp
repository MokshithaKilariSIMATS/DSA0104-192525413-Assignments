#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

enum class Zone { Inner, Middle, Outer };

long long fare(Zone z, int hour) {
    if (hour < 0 || hour > 23) return -1;
    long long base = (z == Zone::Inner ? 1000 :
                      z == Zone::Middle ? 2000 :
                      z == Zone::Outer ? 3000 : -1);
    if (base < 0) return -1;
    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);
    return peak ? base * 120 / 100 : base;
}

struct Test {
    string name;
    Zone zone;
    int hour;
    long long expected;
};

int main() {
    vector<Test> tests = {
        {"T1 Inner 07:59", Zone::Inner, 7, 1000},
        {"T2 Inner 08:00", Zone::Inner, 8, 1200},
        {"T3 Middle 09:59", Zone::Middle, 9, 2400},
        {"T4 Middle 10:00", Zone::Middle,10, 2000},
        {"T5 Outer 17:00", Zone::Outer,17, 3600},
        {"T6 Outer 19:59", Zone::Outer,19, 3600},
        {"T7 Outer 20:00", Zone::Outer,20, 3000}
    };

    int passed = 0;
    cout << "Fare Logic Test Suite\n";
    cout << "---------------------\n";
    for (const auto& t : tests) {
        long long actual = fare(t.zone, t.hour);
        bool ok = actual == t.expected;
        cout << left << setw(20) << t.name
             << " Expected Rs " << setw(6) << right << fixed << setprecision(2) << t.expected/100.0
             << " Actual Rs " << setw(6) << actual/100.0
             << " [" << (ok ? "PASS" : "FAIL") << "]\n";
        if (ok) ++passed;
    }
    cout << "\nResult: " << passed << "/" << tests.size() << " tests passed.\n";
}
