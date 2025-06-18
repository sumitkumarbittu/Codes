import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class JdbcExample {
    public static void main(String[] args) {
        // Database credentials and URL
        String url = "jdbc:mysql://localhost:3306/db1";
        String username = "root";
        String password;

        try {
            password = new String(Files.readAllBytes(Paths.get("/Users/inflasher_b2/Documents/GitHub/Codes/JAVA/password.txt"))).trim();
        } catch (IOException e) {
            throw new RuntimeException("Failed to read password from file", e);
        }
        
        
        try {
            // 1. Load the JDBC driver (not required since JDBC 4.0, but good practice)
            Class.forName("com.mysql.cj.jdbc.Driver");
            
            // 2. Establish connection
            Connection connection = DriverManager.getConnection(url, username, password);
            System.out.println("Database connection established");
            
            // 3. Create a statement
            Statement statement = connection.createStatement();
            
            // 4. Execute a query
            String sqlQuery = "SELECT Code, Name, Designation, Salary FROM Employee";
            ResultSet resultSet = statement.executeQuery(sqlQuery);
            
            // Process the result set
            while (resultSet.next()) {
                String code = resultSet.getString("Code");
                String name = resultSet.getString("Name");
                String designation = resultSet.getString("Designation");
                double Salary = resultSet.getDouble("Salary");
                
                System.out.println("\nCode : " + code + "\nName: " + name + "\nDesignation: " + designation + "\nSalary: " + Salary + "\n");
            }

            // 5. Close resources in reverse order
            try {
                if (resultSet != null) resultSet.close();
                if (statement != null) statement.close();
                if (connection != null) connection.close();
                System.out.println("Database connection closed");
            } catch (SQLException e) {
                e.printStackTrace();
            }

        } catch (ClassNotFoundException e) {
            System.err.println("JDBC driver not found");
            e.printStackTrace();
        } catch (SQLException e) {
            System.err.println("Database connection error");
            e.printStackTrace();
        }
    }
}