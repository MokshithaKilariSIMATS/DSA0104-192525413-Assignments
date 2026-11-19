#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;
    int code = 'A' + 2;
    char c = static_cast<char>(code);
    char ch = 'C';
    bool flag = 5;
    int signedValue = -1;
    unsigned int unsignedValue = 1;

    cout << a / b << " " << static_cast<double>(a) / b << "\n";
    cout << c << " " << static_cast<int>(ch) + 1 << "\n";
    cout << flag << " ";
    cout << boolalpha << (signedValue < unsignedValue) << "\n";
    cout << (signedValue < static_cast<int>(unsignedValue) ? "s < u" : "s >= u") << "\n";
}
