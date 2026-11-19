// Assignment 5 - Task B2: Engineered Error Conditions
package Task02;

public class Main {
    public static class ClaimException extends RuntimeException {
        public ClaimException(String message) { super(message); }
    }
    public static double approve(double billed, double cover) {
        if (billed < 0 || cover < 0) throw new IllegalArgumentException("negative amount");
        if (billed > cover) throw new ClaimException("exceeds cover");
        return billed;
    }
    public static double settle(double billed, double cover) {
        try {
            return approve(billed, cover);
        } catch (ClaimException e) {
            System.out.println("audit: " + e.getMessage());
            throw e; // rethrowing exception
        }
    }
    public static void main(String[] args) {
        System.out.println("=== Assignment 5 - Task B2: Error Handling (Java) ===");
        double[][] cases = {{40000, 50000}, {60000, 50000}, {-1, 50000}};
        for (double[] c : cases) {
            try {
                double paid = settle(c[0], c[1]);
                System.out.printf("approved %.0f%n", paid);
            } catch (ClaimException e) {
                System.out.println("claim rejected: " + e.getMessage());
            } catch (Exception e) {
                System.out.println("error: " + e.getMessage());
            }
        }
    }
}
