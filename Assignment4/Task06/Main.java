// Assignment 4 - Task 6: Vehicle Rental Fleet Design Challenge
package Task06;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static abstract class Vehicle {
        protected String regNo;
        protected double dailyRate;
        public Vehicle(String r, double rate) { this.regNo = r; this.dailyRate = rate; }
        public abstract double computeRental(int days, int lateDays);
        public abstract String getType();
        public String getRegNo() { return regNo; }
    }
    public static class Bicycle extends Vehicle {
        public Bicycle(String r, double rate) { super(r, rate); }
        public double computeRental(int d, int l) { return d * dailyRate + (l * dailyRate * 1.2); }
        public String getType() { return "Bicycle"; }
    }
    public static class TwoWheeler extends Vehicle {
        public TwoWheeler(String r, double rate) { super(r, rate); }
        public double computeRental(int d, int l) { return d * dailyRate + 50.0 + (l * dailyRate * 1.5); }
        public String getType() { return "Two-Wheeler"; }
    }
    public static class Car extends Vehicle {
        private int seats;
        public Car(String r, double rate, int s) { super(r, rate); this.seats = s; }
        public double computeRental(int d, int l) {
            double cost = d * dailyRate + (seats > 5 ? d * 300 : 0);
            return cost + (l * dailyRate * 1.5);
        }
        public String getType() { return "Petrol/Diesel Car"; }
    }
    public static class ElectricCar extends Car {
        private double batteryKWh;
        public ElectricCar(String r, double rate, int s, double bKWh) { super(r, rate, s); this.batteryKWh = bKWh; }
        public double computeRental(int d, int l) {
            double cost = (d * dailyRate * 0.90) + (batteryKWh * 1.2);
            return cost + (l * dailyRate * 1.5);
        }
        public String getType() { return "Electric Car"; }
    }
    public static class ElectricBus extends ElectricCar {
        private double commercialTax;
        public ElectricBus(String r, double rate, double bKWh, int pax, double tax) {
            super(r, rate, pax, bKWh); this.commercialTax = tax;
        }
        public double computeRental(int d, int l) { return d * dailyRate + (commercialTax * d) + (l * dailyRate * 2.0); }
        public String getType() { return "Electric Commercial Bus"; }
    }
    public static void main(String[] args) {
        System.out.println("=== Assignment 4 - Task 6: Vehicle Rental Fleet (Java) ===");
        List<Vehicle> fleet = new ArrayList<>();
        fleet.add(new Bicycle("TN-01-BK-1001", 150));
        fleet.add(new TwoWheeler("TN-02-TW-2002", 450));
        fleet.add(new Car("TN-03-CR-3003", 2200, 7));
        fleet.add(new ElectricCar("TN-04-EC-4004", 2800, 5, 60));
        fleet.add(new ElectricBus("TN-05-EB-5005", 8500, 250, 45, 500));

        for (Vehicle v : fleet) {
            System.out.printf("[%s] Reg: %s | Total Charge (3d + 1d late): Rs %.2f%n",
                    v.getType(), v.getRegNo(), v.computeRental(3, 1));
        }
    }
}
