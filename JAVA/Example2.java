public class Example2 {
    public static void main(String[] args) {
        try {
            int age = 19;
            if (age < 18) {
                throw new ArithmeticException("Age must be 18 or above");
            }
            System.out.println("You are eligible to vote.");
        } catch (ArithmeticException e) {
            System.out.println("Caught Exception: " + e.getMessage());
        } finally {
            System.out.println("This block runs no matter what.");
        }
    }
}
