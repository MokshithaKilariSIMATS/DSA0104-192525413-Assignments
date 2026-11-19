// Assignment 4 - Task 3: Constructors & Member Classes
package Task03;

public class Main {
    public static class Person {
        protected String name; protected int age;
        public Person(String n, int a) { this.name = n; this.age = a; }
    }
    public static class Address {
        private String city; private int pin;
        public Address(String c, int p) { this.city = c; this.pin = p; }
        public String str() { return city + "-" + pin; }
    }
    public static class Student extends Person {
        private long regNo; private Address home;
        public Student(String n, int a, long r, String c, int p) {
            super(n, a);
            this.regNo = r;
            this.home = new Address(c, p);
        }
        public void print() {
            System.out.println(regNo + " " + name + " (" + age + ") " + home.str());
        }
    }
    public static void main(String[] args) {
        System.out.println("=== Assignment 4 - Task 3: Member Classes (Java) ===");
        Student s = new Student("Kavya", 19, 192311001L, "Salem", 636001);
        s.print();
    }
}
