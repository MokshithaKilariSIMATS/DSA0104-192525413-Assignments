// Assignment 4 - Task 5: Method Chaining with 'this'
package Task05;

public class Main {
    public static class Cart {
        private String[] items = new String[10];
        private double[] prices = new double[10];
        private int n = 0;
        private double discount = 0;

        public Cart add(String item, double price) {
            if (n < 10) { items[n] = item; prices[n] = price; n++; }
            return this; // method chaining
        }
        public Cart setDiscount(double discount) {
            this.discount = discount; // disambiguating parameter
            return this;
        }
        public double total() {
            double t = 0;
            for (int i = 0; i < n; i++) t += prices[i];
            return t * (100 - discount) / 100.0;
        }
    }
    public static void main(String[] args) {
        System.out.println("=== Assignment 4 - Task 5: Method Chaining with this (Java) ===");
        Cart c = new Cart();
        c.add("Rice", 60).add("Dal", 120).setDiscount(10);
        c.add("Oil", 180);
        System.out.printf("%.2f%n", c.total());
    }
}
