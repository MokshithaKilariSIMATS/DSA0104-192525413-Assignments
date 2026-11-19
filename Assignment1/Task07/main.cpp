#include <iostream>
using namespace std;

bool canTravelProcedural(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= 5000;
}

bool deductProcedural(long long& balance, long long fare) {
    if (!canTravelProcedural(balance, fare)) return false;
    balance -= fare;
    return true;
}

class SmartCard {
    long long balancePaise;
public:
    static constexpr long long MIN_BALANCE_PAISE = 5000;
    explicit SmartCard(long long initial) : balancePaise(initial) {}

    long long balance() const { return balancePaise; }

    bool canTravel(long long fare) const {
        return fare >= 0 && balancePaise >= fare &&
               balancePaise - fare >= MIN_BALANCE_PAISE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balancePaise -= fare;
        return true;
    }
};

int main() {
    long long proceduralBalance = 10000;
    SmartCard card(10000);

    cout << "Procedural version\n";
    cout << "Fare Rs 10.00: "
         << (deductProcedural(proceduralBalance,1000) ? "Accepted" : "Denied")
         << " | Balance Rs " << proceduralBalance/100 << ".00\n";

    cout << "\nOOP version\n";
    cout << "Fare Rs 10.00: "
         << (card.deduct(1000) ? "Accepted" : "Denied")
         << " | Balance Rs " << card.balance()/100 << ".00\n";

    cout << "Encapsulation check: balance is private inside SmartCard.\n";
}
