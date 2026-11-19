#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const long long journeys[] = {20000, 500000, 3000000};
    const long long farePaise = 3600;

    cout << "Network-scale comparison\n";
    cout << "Maximum fare assumption: Rs 36.00 per journey\n\n";

    for (long long n : journeys) {
        long long total = n * farePaise;
        cout << setw(10) << n << " journeys -> "
             << "Rs " << total/100 << "." << setw(2) << setfill('0') << total%100
             << setfill(' ') << " | paise = " << total
             << " | int32 = " << (total <= INT_MAX ? "Fits" : "OVERFLOW")
             << "\n";
    }

    cout << "\nActual environment values\n";
    cout << "sizeof(int)       = " << sizeof(int) << "\n";
    cout << "sizeof(long long) = " << sizeof(long long) << "\n";
    cout << "sizeof(double)    = " << sizeof(double) << "\n";
    cout << "INT_MAX           = " << INT_MAX << "\n";
    cout << "LLONG_MAX         = " << LLONG_MAX << "\n";

    double d = 0.0;
    for (int i = 0; i < 1000000; ++i) d += 0.10;
    long long paise = 0;
    for (int i = 0; i < 1000000; ++i) paise += 10;

    cout << fixed << setprecision(10);
    cout << "\nDouble sum of 0.10 x 1,000,000 = " << d << "\n";
    cout << "Integer paise sum              = " << paise << " paise\n";
    cout << "Integer representation avoids floating-point accumulation error.\n";
}
