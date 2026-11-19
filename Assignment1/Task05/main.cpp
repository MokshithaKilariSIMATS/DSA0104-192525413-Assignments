#include <iostream>
using namespace std;

int main() {
    int a = 5 + 3 * 2;
    int b = (5 + 3) * 2;
    int x = 5, y = 3;
    int z = x++ + ++y;
    int maxValue = (x > y) ? x : y;
    int expr = (maxValue % 4) * 2;

    cout << a << " " << b << "\n";
    cout << z << " " << x << " " << y << "\n";
    cout << expr << "\n";
    cout << 10 / 3 << " " << 10 % 3 << " "
         << -10 / 3 << " " << -10 % 3 << "\n";

    int k = 0;
    for (int i = 0; i <= 9; i += 3) k += i;
    cout << k << "\n";

    int hour = 18;
    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    cout << "Peak at " << hour << ":00 = " << boolalpha << peak << "\n";
}
