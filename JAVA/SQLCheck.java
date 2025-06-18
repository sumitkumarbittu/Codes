import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class SQLCheck {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/db1";
        String user = "root";
        String password;

        try {
            password = new String(Files.readAllBytes(Paths.get("/Users/inflasher_b2/Documents/GitHub/Codes/JAVA/password.txt"))).trim();
        } catch (IOException e) {
            throw new RuntimeException("Failed to read password from file", e);
        }

        try {
            Connection conn = DriverManager.getConnection(url, user, password);
            System.out.println("Connected to MySQL successfully!");
            conn.close();
        } catch (SQLException e) {
            System.err.println("MySQL connection error: " + e.getMessage());
        }
    }
}