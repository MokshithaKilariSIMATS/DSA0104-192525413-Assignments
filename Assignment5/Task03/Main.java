// Assignment 5 - Task B3: Cost of Exceptions vs Return Codes
package Task03;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Assignment 5 - Task B3: Exception Benchmark (Java) ===");
        int n = 1000000;
        long start = System.currentTimeMillis();
        int valid = 0;
        for (int i = 0; i < n; i++) {
            if (i % 100 != 0) valid++;
        }
        long end = System.currentTimeMillis();
        System.out.printf("Processed %d claims in %d ms (Valid: %d)%n", n, (end - start), valid);
    }
}
