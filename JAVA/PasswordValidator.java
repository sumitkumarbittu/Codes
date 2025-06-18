import java.util.Scanner;

public class PasswordValidator {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        try {
            System.out.print("Enter username: ");
            String username = scanner.nextLine();
            
            System.out.print("Enter password: ");
            String password = scanner.nextLine();
            
            if (approPass(password)) {
                System.out.println("Welcome, " + username + "!");
            } else {
                throw new InvalidPasswordException("Password does not meet requirements");
            }
        } catch (InvalidPasswordException e) {
            System.out.println("Error: " + e.getMessage());
            System.out.println("Password must contain at least:");
            System.out.println("- One lowercase letter");
            System.out.println("- One uppercase letter");
            System.out.println("- One digit");
            System.out.println("- One special character");
        } finally {
            scanner.close();
        }
    }
    
    public static boolean approPass(String password) {
        boolean hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        
        if (password.length() < 8) {
            return false;
        }
        
        for (char c : password.toCharArray()) {
            if (Character.isLowerCase(c)) {
                hasLower = true;
            } else if (Character.isUpperCase(c)) {
                hasUpper = true;
            } else if (Character.isDigit(c)) {
                hasDigit = true;
            } else {
                // Special character check
                if (!Character.isLetterOrDigit(c)) {
                    hasSpecial = true;
                }
            }
            
            // Early exit if all conditions are met
            if (hasLower && hasUpper && hasDigit && hasSpecial) {
                return true;
            }
        }
        
        return hasLower && hasUpper && hasDigit && hasSpecial;
    }
    
    static class InvalidPasswordException extends Exception {
        public InvalidPasswordException(String message) {
            super(message);
        }
    }
}