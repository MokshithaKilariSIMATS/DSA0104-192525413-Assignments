#include <iostream>
#include <string>

// Virtual base class Person
class Person {
protected:
    std::string name;
    int id;
    std::string phone;

public:
    Person(const std::string& n = "Unknown", int i = 0, const std::string& p = "000-0000")
        : name(n), id(i), phone(p) {
        std::cout << "[CONSTRUCT] Person (" << name << ")\n";
    }
    virtual ~Person() = default;

    virtual void display() const {
        std::cout << "ID: " << id << " | Name: " << name << " | Phone: " << phone;
    }
};

// Student inherits virtually from Person
class Student : virtual public Person {
protected:
    std::string programme;
    double cgpa;

public:
    Student(const std::string& n, int i, const std::string& p, const std::string& prog, double c)
        : Person(n, i, p), programme(prog), cgpa(c) {
        std::cout << "[CONSTRUCT] Student (" << programme << ")\n";
    }

    void display() const override {
        Person::display();
        std::cout << " | Prog: " << programme << " | CGPA: " << cgpa;
    }
};

// Staff inherits virtually from Person
class Staff : virtual public Person {
protected:
    std::string department;
    double salary;

public:
    Staff(const std::string& n, int i, const std::string& p, const std::string& dept, double s)
        : Person(n, i, p), department(dept), salary(s) {
        std::cout << "[CONSTRUCT] Staff (" << department << ")\n";
    }

    void display() const override {
        Person::display();
        std::cout << " | Dept: " << department << " | Salary: Rs " << salary;
    }
};

// TeachingAssistant resolves diamond via virtual base inheritance
class TeachingAssistant : public Student, public Staff {
private:
    int labHoursAssigned;

public:
    // The most derived class must invoke the virtual base constructor directly!
    TeachingAssistant(const std::string& n, int i, const std::string& p,
                      const std::string& prog, double c,
                      const std::string& dept, double s, int lh)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, dept, s),
          labHoursAssigned(lh) {
        std::cout << "[CONSTRUCT] TeachingAssistant (" << labHoursAssigned << " hrs/wk)\n";
    }

    void display() const override {
        Person::display();
        std::cout << " | Prog: " << programme << " | CGPA: " << cgpa
                  << " | Dept: " << department << " | Salary: Rs " << salary
                  << " | Lab Hours: " << labHoursAssigned << " hrs/week\n";
    }
};

// Predict the Output verification struct from assignment sheet
struct PredPerson { PredPerson() { std::cout << "Person "; } };
struct PredStudent : virtual PredPerson { PredStudent() { std::cout << "Student "; } };
struct PredStaff : virtual PredPerson { PredStaff() { std::cout << "Staff "; } };
struct PredTeachingAssistant : PredStudent, PredStaff {
    PredTeachingAssistant() { std::cout << "TA "; }
};

int main() {
    std::cout << "=== Assignment 4 - Task 2: University People Management & Diamond Problem ===\n\n";

    std::cout << "--- 1. Creating TeachingAssistant (Tracing Construction) ---\n";
    TeachingAssistant ta("Kavya", 101, "9876543210", "AI & ML", 9.4, "CSE", 25000, 10);
    std::cout << "\nTA Record Details:\n";
    ta.display();

    std::cout << "\n--- 2. Predict the Output Verification ---\n";
    std::cout << "Actual execution:   ";
    {
        PredTeachingAssistant predTA;
        std::cout << '\n';
    }
    std::cout << "Expected output:   Person Student Staff TA \n";

    return 0;
}
