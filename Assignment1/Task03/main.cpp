#include <climits>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long farePaise = 1020;
    bool peak = true;
    int hour = 9;
    char grade = 'A';
    double measurement = 12.5;

    cout << "Fare (paise) : " << farePaise << "\n";
    cout << "Peak flag    : " << boolalpha << peak << "\n";
    cout << "Hour         : " << hour << "\n";
    cout << "Grade        : " << grade << "\n";
    cout << "Measurement  : " << fixed << setprecision(1) << measurement << "\n\n";

    cout << "sizeof(int)       = " << sizeof(int) << " bytes\n";
    cout << "sizeof(long long) = " << sizeof(long long) << " bytes\n";
    cout << "sizeof(double)    = " << sizeof(double) << " bytes\n";
    cout << "INT_MAX           = " << INT_MAX << "\n";
    cout << "LLONG_MAX         = " << LLONG_MAX << "\n";

    long long networkPaise = 3000000LL * 3600LL;
    cout << "\n3,000,000 journeys at Rs 36.00 = "
         << networkPaise << " paise\n";
}
