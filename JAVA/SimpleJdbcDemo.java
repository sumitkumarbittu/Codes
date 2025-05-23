import java.io.IOException;
import java.lang.String;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.sql.*;

public class SimpleJdbcDemo {
    static {
        try {
            // Explicitly load the driver class
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            throw new RuntimeException("MySQL JDBC Driver not found", e);
        }
    }
    // Database configuration
    private static final String DB_URL = "jdbc:mysql://localhost:3306/db1";
    private static final String USER = "root";
    private static final String PASS;

    static {
        try {
            PASS = new String(Files.readAllBytes(Paths.get("/Users/inflasher_b2/Documents/GitHub/Codes/JAVA/password.txt"))).trim();
        } catch (IOException e) {
            throw new RuntimeException("Failed to read password from file", e);
        }
    }

    public static void main(String[] args) {
        try {
            // 1. Create table
            createStudentTable();
            
            // 2. Insert sample records
            insertSampleStudents();
            
            // 3. Retrieve and display all students
            displayAllStudents();
            
        } catch (SQLException e) {
            System.err.println("Database error:");
            e.printStackTrace();
        }
    }

    private static void createStudentTable() throws SQLException {
        String sql = "CREATE TABLE IF NOT EXISTS students (" +
                    "id INT AUTO_INCREMENT PRIMARY KEY, " +
                    "name VARCHAR(50) NOT NULL, " +
                    "email VARCHAR(50) UNIQUE, " +
                    "age INT)";
        
        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             Statement stmt = conn.createStatement()) {
            
            stmt.executeUpdate(sql);
            System.out.println("Table created successfully");
        }
    }

    private static void insertSampleStudents() throws SQLException {
        String[] names = {"A", "B", "C"};
        String[] emails = {"a@example.com", "b@example.com", "c@example.com"};
        int[] ages = {20, 22, 21};
        
        String sql = "INSERT INTO students (name, email, age) VALUES (?, ?, ?)";
        
        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            
            for (int i = 0; i < names.length; i++) {
                pstmt.setString(1, names[i]);
                pstmt.setString(2, emails[i]);
                pstmt.setInt(3, ages[i]);
                pstmt.executeUpdate();
            }
            System.out.println("Inserted " + names.length + " student records");
        }
    }

    private static void displayAllStudents() throws SQLException {
        String sql = "SELECT id, name, email, age FROM students";
        
        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {
            
            System.out.println("\nCurrent Student Records:");
            System.out.printf("%-5s %-20s %-25s %-5s%n", "ID", "Name", "Email", "Age");
            System.out.println("-------------------------------------------------------");
            
            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                String email = rs.getString("email");
                int age = rs.getInt("age");
                
                System.out.printf("%-5d %-20s %-25s %-5d%n", id, name, email, age);
            }
        }
    }
}