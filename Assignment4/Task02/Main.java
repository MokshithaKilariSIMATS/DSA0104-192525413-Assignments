// Assignment 4 - Task 2: University People Management & Interface Composition
package Task02;

public class Main {
    // In Java, multiple inheritance of classes is achieved via interfaces or composition
    public static class Person {
        protected String name; protected int id; protected String phone;
        public Person(String n, int id, String p) { this.name = n; this.id = id; this.phone = p; }
        public String getDetails() { return "ID: " + id + " | Name: " + name + " | Phone: " + phone; }
    }
    public interface StudentRole { String getProgramme(); double getCgpa(); }
    public interface StaffRole { String getDepartment(); double getSalary(); }

    public static class TeachingAssistant extends Person implements StudentRole, StaffRole {
        private String programme; private double cgpa;
        private String department; private double salary;
        private int labHours;

        public TeachingAssistant(String n, int id, String p, String prog, double c, String dept, double s, int lh) {
            super(n, id, p);
            this.programme = prog; this.cgpa = c;
            this.department = dept; this.salary = s;
            this.labHours = lh;
        }
        public String getProgramme() { return programme; }
        public double getCgpa() { return cgpa; }
        public String getDepartment() { return department; }
        public double getSalary() { return salary; }
        public void display() {
            System.out.println(getDetails() + " | Prog: " + programme + " | CGPA: " + cgpa +
                               " | Dept: " + department + " | Salary: Rs " + salary + " | Lab Hours: " + labHours);
        }
    }
    public static void main(String[] args) {
        System.out.println("=== Assignment 4 - Task 2: University Management (Java) ===");
        TeachingAssistant ta = new TeachingAssistant("Kavya", 101, "9876543210", "AI & ML", 9.4, "CSE", 25000, 10);
        ta.display();
    }
}
