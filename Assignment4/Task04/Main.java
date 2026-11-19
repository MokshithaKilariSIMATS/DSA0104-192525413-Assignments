// Assignment 4 - Task 4: Polymorphic Accounts
package Task04;

public class Main {
    public static class Account {
        public double rate() { return 3.5; }
    }
    public static class SeniorAccount extends Account {
        private double[] history = new double[100];
        @Override
        public double rate() { return 4.0; } // In Java all instance methods are virtual by default!
    }
    public static void main(String[] args) {
        System.out.println("=== Assignment 4 - Task 4: Polymorphic Accounts (Java) ===");
        Account[] accounts = { new Account(), new SeniorAccount() };
        for (Account a : accounts) {
            System.out.println("Interest rate: " + a.rate() + "%");
        }
    }
}
