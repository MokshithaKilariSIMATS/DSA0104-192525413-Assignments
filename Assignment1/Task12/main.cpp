#include <array>
#include <iostream>
#include <optional>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };

constexpr array<long long,4> BASE_FARE = {1000,2000,3000,6000};

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}

optional<long long> revisedFare(Zone zone, int hour, bool weekend) {
    if (hour < 0 || hour > 23) return nullopt;
    size_t index = static_cast<size_t>(zone);
    if (index >= BASE_FARE.size()) return nullopt;

    long long base = BASE_FARE[index];

    // Weekend discount replaces the peak surcharge.
    if (weekend) return base - base * 10 / 100;
    if (isPeak(hour)) return base + base * 20 / 100;
    return base;
}

class MonthlyPass {
    Zone first, second;
    int startDay, endDay;
public:
    MonthlyPass(Zone a, Zone b, int start, int end)
        : first(a), second(b), startDay(start), endDay(end) {}

    bool isValid(int day) const {
        return day >= startDay && day <= endDay;
    }

    bool covers(Zone z, int day) const {
        return isValid(day) && (z == first || z == second);
    }
};

void showFare(const string& label, Zone z, int hour, bool weekend) {
    auto f = revisedFare(z, hour, weekend);
    cout << label << " -> ";
    if (f) cout << "Rs " << *f/100 << "." << *f%100 << "\n";
    else cout << "Invalid\n";
}

int main() {
    cout << "Revised Fare Policy\n";
    cout << "-------------------\n";
    showFare("Airport off-peak weekday", Zone::Airport, 12, false);
    showFare("Airport peak weekday", Zone::Airport, 8, false);
    showFare("Airport peak weekend", Zone::Airport, 8, true);
    showFare("Inner weekend off-peak", Zone::Inner, 14, true);

    MonthlyPass pass(Zone::Inner, Zone::Airport, 1, 30);
    cout << "\nMonthly Pass: Inner + Airport, valid days 1-30\n";
    cout << "Airport day 15 covered : " << boolalpha
         << pass.covers(Zone::Airport,15) << "\n";
    cout << "Outer day 15 covered   : " << pass.covers(Zone::Outer,15) << "\n";
    cout << "Airport day 31 covered : " << pass.covers(Zone::Airport,31) << "\n";
}
