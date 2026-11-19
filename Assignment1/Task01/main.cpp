#include <iostream>
#include <string>
using namespace std;

class SmartCard {
    long long balancePaise;
public:
    explicit SmartCard(long long balance) : balancePaise(balance) {}
    long long balance() const { return balancePaise; }
    bool canTravel(long long fare) const {
        return fare >= 0 && balancePaise - fare >= 5000;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balancePaise -= fare;
        return true;
    }
};

class Passenger {
    string id, category;
public:
    Passenger(string i, string c) : id(i), category(c) {}
    string getCategory() const { return category; }
    bool isEligibleForConcession() const {
        return category == "student" || category == "senior";
    }
    void display() const {
        cout << "Passenger ID : " << id << "\n"
             << "Category     : " << category << "\n"
             << "Concession   : "
             << (isEligibleForConcession() ? "Eligible" : "Not eligible") << "\n";
    }
};

int main() {
    Passenger p("P1025", "student");
    SmartCard card(10000);

    p.display();
    cout << "Initial card balance : Rs 100.00\n";
    cout << "Fare for journey     : Rs 12.00\n";

    if (card.deduct(1200))
        cout << "Journey accepted     : Yes\n";
    else
        cout << "Journey accepted     : No\n";

    cout << "Remaining balance    : Rs "
         << card.balance()/100 << "." << card.balance()%100 << "\n";
}
