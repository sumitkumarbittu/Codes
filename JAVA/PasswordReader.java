import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

public class PasswordReader {
    public static void main(String[] args) {
        try {
            // Read file with explicit charset and trim whitespace
            String password = new String(
                Files.readAllBytes(Paths.get("/Users/inflasher_b2/Documents/GitHub/Codes/JAVA/password.txt")), 
                StandardCharsets.UTF_8
            ).trim();
            
            System.out.println("Password length: " + password.length());
            // Don't print actual password in production!
            // System.out.println(password); 
        } catch (IOException e) {
            System.err.println("Error reading password file: " + e.getMessage());
            System.exit(1);
        }
    }
}