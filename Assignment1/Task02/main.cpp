#include <iostream>
using namespace std;

class FareDemo {
public:
    static constexpr long long MIN_BALANCE_PAISE = 5000;
    void show() const {
        int hour = 8;
        bool peak = true;
        cout << "Keyword examples   : class, constexpr, if, return\n";
        cout << "Identifier examples: FareDemo, MIN_BALANCE_PAISE, hour\n";
        cout << "Constant values    : " << MIN_BALANCE_PAISE << " paise, 20 percent\n";
        cout << "Operators           : +  -  >=  &&  ?:  %\n";
        cout << "enum class example  : Zone::Inner\n";
        cout << "Current hour        : " << hour << "\n";
        cout << boolalpha << "Peak status         : " << peak << "\n";
    }
};

enum class Zone { Inner, Middle, Outer };

int main() {
    FareDemo demo;
    demo.show();
    Zone z = Zone::Inner;
    cout << "Selected zone       : "
         << (z == Zone::Inner ? "Inner" : "Other") << "\n";
}
