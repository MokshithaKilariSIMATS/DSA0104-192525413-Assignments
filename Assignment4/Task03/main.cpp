#include <iostream>
#include <string>

// Prediction struct code from assignment sheet
struct Engine {
    Engine() { std::cout << "Engine "; }
    ~Engine() { std::cout << "~Engine "; }
};

struct Vehicle {
    Vehicle() { std::cout << "Vehicle "; }
    ~Vehicle() { std::cout << "~Vehicle "; }
};

struct Car : Vehicle {
    Engine e;
    Car() { std::cout << "Car "; }
    ~Car() { std::cout << "~Car "; }
};

// Base class Person
class Person {
protected:
    std::string name;
    int age;
public:
    Person(const std::string& n, int a) : name(n), age(a) {}
};

// Member class Address (Composition)
class Address {
    std::string city;
    int pin;
public:
    Address(const std::string& c, int p) : city(c), pin(p) {}
    std::string str() const { return city + "-" + std::to_string(pin); }
};

// Derived class Student
class Student : public Person {
    long long regNo;
    Address home;
public:
    // TODO 1: Write the constructor: initialise the Person base, regNo and the home Address member in the initializer list
    Student(const std::string& n, int a, long long r, const std::string& c, int p)
        : Person(n, a), regNo(r), home(c, p) {}

    void print() const {
        std::cout << regNo << ' ' << name << " (" << age << ") " << home.str() << '\n';
    }
};

int main() {
    std::cout << "=== Assignment 4 - Task 3: Constructors in Derived & Member Classes ===\n\n";

    // 1. Official "Complete the Code" execution
    std::cout << "Official Complete the Code Output:\n";
    Student s("Kavya", 19, 192311001, "Salem", 636001);
    s.print();

    // 2. Predict the Output Verification
    std::cout << "\nPredict the Output (Vehicle, Engine, Car) Verification:\n";
    std::cout << "Actual execution:   ";
    {
        Car c;
        std::cout << "| ";
    }
    std::cout << '\n';
    std::cout << "Expected output:   Vehicle Engine Car | ~Car ~Engine ~Vehicle \n";

    return 0;
}
