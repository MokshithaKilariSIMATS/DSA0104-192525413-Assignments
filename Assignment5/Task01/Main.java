// Assignment 5 - Task B1: Polymorphic Billing Validation
package Task01;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static abstract class Bill {
        protected String patient;
        public Bill(String p) { this.patient = p; }
        public abstract double total();
        public String type() { return "Bill"; }
        public void print() {
            System.out.printf("%s %s: %.0f%n", type(), patient, total());
        }
    }
    public static class OutPatient extends Bill {
        private double consultation, tests;
        public OutPatient(String p, double c, double t) { super(p); this.consultation = c; this.tests = t; }
        public double total() { return consultation + tests; }
        public String type() { return "OP"; }
    }
    public static class InPatient extends Bill {
        private int days; private double perDay, surgery;
        public InPatient(String p, int d, double rate, double s) {
            super(p); this.days = d; this.perDay = rate; this.surgery = s;
        }
        public double total() { return days * perDay + surgery; }
        public String type() { return "IP"; }
    }
    public static void main(String[] args) {
        System.out.println("=== Assignment 5 - Task B1: Polymorphic Billing (Java) ===");
        List<Bill> bills = new ArrayList<>();
        bills.add(new OutPatient("Ravi", 500, 1200));
        bills.add(new InPatient("Meena", 3, 2500, 40000));

        double sum = 0;
        for (Bill b : bills) { b.print(); sum += b.total(); }
        System.out.printf("Total %.0f%n", sum);
    }
}
