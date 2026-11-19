// Assignment 4 - Task 1: Class Design Review
package Task01;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static abstract class Staff {
        protected String name;
        protected int id;
        public Staff(String name, int id) { this.name = name; this.id = id; }
        public abstract double pay();
        public abstract String getRole();
        public void display() {
            System.out.printf("[%s] ID: %d | Name: %s | Monthly Pay: Rs %.2f%n", getRole(), id, name, pay());
        }
    }
    public static class Professor extends Staff {
        private double basic, da, research;
        public Professor(String n, int id, double b, double r) {
            super(n, id); this.basic = b; this.research = r; this.da = 0.42;
        }
        public double pay() { return basic + basic * da + research; }
        public String getRole() { return "Professor"; }
    }
    public static class LabAssistant extends Staff {
        private double basic, da;
        public LabAssistant(String n, int id, double b) {
            super(n, id); this.basic = b; this.da = 0.42;
        }
        public double pay() { return basic + basic * da; }
        public String getRole() { return "Lab Assistant"; }
    }
    public static class GuestFaculty extends Staff {
        private double hours, rate;
        public GuestFaculty(String n, int id, double h, double r) {
            super(n, id); this.hours = h; this.rate = r;
        }
        public double pay() { return hours * rate; }
        public String getRole() { return "Guest Faculty"; }
    }
    public static void main(String[] args) {
        System.out.println("=== Assignment 4 - Task 1: Refactored Staff Hierarchy (Java) ===");
        List<Staff> staffList = new ArrayList<>();
        staffList.add(new Professor("Dr. Anand Kumar", 101, 80000, 15000));
        staffList.add(new LabAssistant("Bala Murugan", 202, 35000));
        staffList.add(new GuestFaculty("Chitra Ramesh", 303, 40, 1200));

        double sum = 0;
        for (Staff s : staffList) { s.display(); sum += s.pay(); }
        System.out.printf("Total Payroll: Rs %.2f%n", sum);
    }
}
