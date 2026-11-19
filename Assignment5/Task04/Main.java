// Assignment 5 - Task B4: Final Engineering Extension
package Task04;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static abstract class Bill {
        protected String patient;
        public Bill(String p) { this.patient = p; }
        public abstract double total();
        public abstract String type();
    }
    public static class OutPatient extends Bill {
        public OutPatient(String p) { super(p); }
        public double total() { return 1700; }
        public String type() { return "OP"; }
    }
    public static class InPatient extends Bill {
        public InPatient(String p) { super(p); }
        public double total() { return 47500; }
        public String type() { return "IP"; }
    }
    // New Extended Bill Type
    public static class DayCareBill extends Bill {
        public DayCareBill(String p) { super(p); }
        public double total() { return 25500; }
        public String type() { return "DayCare"; }
    }
    public static void main(String[] args) {
        System.out.println("=== Assignment 5 - Task B4: Extended Billing Architecture (Java) ===");
        List<Bill> bills = new ArrayList<>();
        bills.add(new OutPatient("Ravi"));
        bills.add(new InPatient("Meena"));
        bills.add(new DayCareBill("Suresh"));

        for (Bill b : bills) {
            System.out.printf("[%s] Patient: %s | Total: Rs %.2f%n", b.type(), b.patient, b.total());
        }
    }
}
