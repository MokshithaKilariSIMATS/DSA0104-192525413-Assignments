#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int readHour() {
    int hour;
    while (true) {
        cout << "Enter hour (0-23): ";
        if (cin >> hour) {
            if (hour >= 0 && hour <= 23) return hour;
            cout << "Hour must be between 0 and 23.\n";
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number.\n";
        }
    }
}

void printMoney(long long paise) {
    cout << "Rs " << paise / 100 << '.'
         << setw(2) << setfill('0') << paise % 100
         << setfill(' ') << "\n";
}

int main() {
    int hour = readHour();
    cout << "Valid hour accepted: " << hour << ":00\n";
    cout << "Formatted fare: ";
    printMoney(1020);
}
