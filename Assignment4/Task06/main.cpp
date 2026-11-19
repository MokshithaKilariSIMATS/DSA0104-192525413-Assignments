#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

// Abstract Base Class
class Vehicle {
protected:
    std::string regNo;
    double dailyRate;
    bool isRented;

public:
    Vehicle(const std::string& reg, double rate)
        : regNo(reg), dailyRate(rate), isRented(false) {}

    virtual ~Vehicle() = default;

    virtual double computeRental(int days, int daysLate = 0) const = 0;
    virtual std::string getType() const = 0;

    bool rentVehicle() {
        if (isRented) return false;
        isRented = true;
        return true;
    }

    bool returnVehicle() {
        if (!isRented) return false;
        isRented = false;
        return true;
    }

    std::string getRegNo() const { return regNo; }
    bool getStatus() const { return isRented; }
};

// 1. Bicycle (Non-motorized)
class Bicycle : public Vehicle {
public:
    Bicycle(const std::string& reg, double rate = 150.0) : Vehicle(reg, rate) {}

    double computeRental(int days, int daysLate = 0) const override {
        double cost = days * dailyRate;
        if (daysLate > 0) cost += daysLate * (dailyRate * 1.2); // 20% late penalty
        return cost;
    }

    std::string getType() const override { return "Bicycle"; }
};

// Intermediate base class for Motor Vehicles
class MotorVehicle : public Vehicle {
protected:
    double fuelOrChargeLevel; // percentage 0 - 100%
    std::string serviceDueDate;

public:
    MotorVehicle(const std::string& reg, double rate, double level, const std::string& sDate)
        : Vehicle(reg, rate), fuelOrChargeLevel(level), serviceDueDate(sDate) {}
};

// 2. Two-Wheeler
class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(const std::string& reg, double rate, double fuel, const std::string& sDate)
        : MotorVehicle(reg, rate, fuel, sDate) {}

    double computeRental(int days, int daysLate = 0) const override {
        double cost = days * dailyRate + 50.0; // Rs 50 helmet sanitizer fee
        if (daysLate > 0) cost += daysLate * (dailyRate * 1.5);
        return cost;
    }

    std::string getType() const override { return "Two-Wheeler"; }
};

// 3. Car
class Car : public MotorVehicle {
protected:
    int seatingCapacity;

public:
    Car(const std::string& reg, double rate, double fuel, const std::string& sDate, int seats)
        : MotorVehicle(reg, rate, fuel, sDate), seatingCapacity(seats) {}

    double computeRental(int days, int daysLate = 0) const override {
        double cost = days * dailyRate;
        if (seatingCapacity > 5) cost += days * 300.0; // SUV/large vehicle surcharge
        if (daysLate > 0) cost += daysLate * (dailyRate * 1.5);
        return cost;
    }

    std::string getType() const override { return "Petrol/Diesel Car"; }
};

// 4. Electric Car
class ElectricCar : public Car {
protected:
    double batteryCapacityKWh;
    double chargePerKWh;

public:
    ElectricCar(const std::string& reg, double rate, double batteryPct, const std::string& sDate,
                int seats, double batteryKWh, double perKWh = 12.0)
        : Car(reg, rate, batteryPct, sDate, seats),
          batteryCapacityKWh(batteryKWh), chargePerKWh(perKWh) {}

    double computeRental(int days, int daysLate = 0) const override {
        double greenDiscount = 0.90; // 10% eco discount
        double cost = (days * dailyRate * greenDiscount) + (batteryCapacityKWh * chargePerKWh * 0.1);
        if (daysLate > 0) cost += daysLate * (dailyRate * 1.5);
        return cost;
    }

    std::string getType() const override { return "Electric Car"; }
};

// 5. EXTENSION: Electric Bus added without changing ANY existing classes
class ElectricBus : public ElectricCar {
private:
    int passengerCapacity;
    double commercialTax;

public:
    ElectricBus(const std::string& reg, double rate, double batteryPct, const std::string& sDate,
                double batteryKWh, int pax, double tax = 500.0)
        : ElectricCar(reg, rate, batteryPct, sDate, pax, batteryKWh),
          passengerCapacity(pax), commercialTax(tax) {}

    double computeRental(int days, int daysLate = 0) const override {
        double baseCost = days * dailyRate + (commercialTax * days);
        if (daysLate > 0) cost_late(baseCost, daysLate);
        return baseCost;
    }

    void cost_late(double& base, int late) const {
        base += late * (dailyRate * 2.0);
    }

    std::string getType() const override { return "Electric Commercial Bus"; }
};

int main() {
    std::cout << "=== Assignment 4 - Task 6: Vehicle Rental Fleet Design Challenge ===\n\n";

    // Heterogeneous fleet managed through an array of base-class pointers
    std::vector<std::unique_ptr<Vehicle>> fleet;
    fleet.push_back(std::make_unique<Bicycle>("TN-01-BK-1001", 150.0));
    fleet.push_back(std::make_unique<TwoWheeler>("TN-02-TW-2002", 450.0, 85.0, "2026-12-01"));
    fleet.push_back(std::make_unique<Car>("TN-03-CR-3003", 2200.0, 90.0, "2027-01-15", 7));
    fleet.push_back(std::make_unique<ElectricCar>("TN-04-EC-4004", 2800.0, 100.0, "2027-03-01", 5, 60.0));
    // Extension: ElectricBus seamlessly integrated
    fleet.push_back(std::make_unique<ElectricBus>("TN-05-EB-5005", 8500.0, 95.0, "2027-02-10", 250.0, 45));

    std::cout << "Fleet Rental Simulation (Duration: 3 days, 1 day late return):\n";
    std::cout << "----------------------------------------------------------------------\n";
    for (const auto& v : fleet) {
        v->rentVehicle();
        double charge = v->computeRental(3, 1);
        std::cout << "[" << std::left << std::setw(25) << v->getType() << "] "
                  << "Reg: " << std::setw(15) << v->getRegNo()
                  << " | Total Charge (3d + 1d late): Rs " << std::fixed << std::setprecision(2) << charge << '\n';
        v->returnVehicle();
    }

    return 0;
}
