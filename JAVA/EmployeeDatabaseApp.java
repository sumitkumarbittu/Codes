import java.awt.*;
import java.io.IOException;
import java.lang.String;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.sql.*;
import javax.swing.*;


public class EmployeeDatabaseApp {
    private JFrame frame;
    private JTextField nameField, codeField, designationField, salaryField;
    private Connection connection;

    public EmployeeDatabaseApp() {
        setupDatabase();
        buildGUI();
    }

    private void setupDatabase() {
        try {
            //Load driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            
            String url = "jdbc:mysql://localhost:3306/db1";
            String user = "root";
            String password;

            try {
                password = new String(Files.readAllBytes(Paths.get("/Users/inflasher_b2/Documents/GitHub/Codes/JAVA/password.txt"))).trim();
            } catch (IOException e) {
                throw new RuntimeException("Failed to read password from file", e);
            }
            
            System.out.println("Attempting to connect to: " + url);
            connection = DriverManager.getConnection(url, user, password);
            System.out.println("Connection successful!");
    
            // 3. Create table
            try (Statement stmt = connection.createStatement()) {
                stmt.executeUpdate("CREATE TABLE IF NOT EXISTS Employee (" +
                    "Name VARCHAR(50), " +
                    "Code VARCHAR(20) PRIMARY KEY, " +
                    "Designation VARCHAR(50), " +
                    "Salary DECIMAL(10,2))");
                System.out.println("Table created/verified");
            }
            
        } catch (ClassNotFoundException e) {
            JOptionPane.showMessageDialog(frame, "MySQL Driver missing! Add mysql-connector-java.jar to your classpath.");
            e.printStackTrace();
            System.exit(1);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Database connection failed:\n" + e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
    }

    private void buildGUI() {
        frame = new JFrame("Employee Entry Form");
        frame.setSize(500, 300);  // Increased width for better display
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        JPanel form = new JPanel(new GridLayout(4, 2, 5, 5));
        nameField = new JTextField();
        codeField = new JTextField();
        designationField = new JTextField();
        salaryField = new JTextField();

        form.add(new JLabel("Name:"));
        form.add(nameField);
        form.add(new JLabel("Code:"));
        form.add(codeField);
        form.add(new JLabel("Designation:"));
        form.add(designationField);
        form.add(new JLabel("Salary:"));
        form.add(salaryField);

        JPanel buttons = new JPanel();
        JButton save = new JButton("Save");
        JButton update = new JButton("Update");
        JButton delete = new JButton("Delete");
        JButton show = new JButton("Show All");
        JButton reset = new JButton("Reset");

        buttons.add(save);
        buttons.add(update);
        buttons.add(delete);
        buttons.add(show);
        buttons.add(reset);

        save.addActionListener(e -> saveEmployee());
        update.addActionListener(e -> updateEmployee());
        delete.addActionListener(e -> deleteEmployee());
        show.addActionListener(e -> showEmployees());
        reset.addActionListener(e -> clearFields());

        frame.add(form, BorderLayout.CENTER);
        frame.add(buttons, BorderLayout.SOUTH);
        frame.setVisible(true);
    }

    private void saveEmployee() {
        try {
            if (connection == null || connection.isClosed()) {
                JOptionPane.showMessageDialog(frame, "Database connection is not available");
                return;
            }

            PreparedStatement ps = connection.prepareStatement(
                    "INSERT INTO Employee (Name, Code, Designation, Salary) VALUES (?, ?, ?, ?)");
            ps.setString(1, nameField.getText());
            ps.setString(2, codeField.getText());
            ps.setString(3, designationField.getText());
            ps.setDouble(4, Double.parseDouble(salaryField.getText()));
            ps.executeUpdate();
            JOptionPane.showMessageDialog(frame, "Employee saved!");
            clearFields();
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Invalid salary format. Please enter a valid number.");
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Could not save employee:\n" + e.getMessage());
        }
    }

    private void updateEmployee() {
        try {
            if (connection == null || connection.isClosed()) {
                JOptionPane.showMessageDialog(frame, "Database connection is not available");
                return;
            }

            PreparedStatement ps = connection.prepareStatement(
                    "UPDATE Employee SET Name=?, Designation=?, Salary=? WHERE Code=?");
            ps.setString(1, nameField.getText());
            ps.setString(2, designationField.getText());
            ps.setDouble(3, Double.parseDouble(salaryField.getText()));
            ps.setString(4, codeField.getText());
            int updated = ps.executeUpdate();
            String msg = (updated > 0) ? "Employee updated!" : "Employee code not found.";
            JOptionPane.showMessageDialog(frame, msg);
            clearFields();
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Invalid salary format. Please enter a valid number.");
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Update failed:\n" + e.getMessage());
        }
    }

    private void deleteEmployee() {
        try {
            if (connection == null || connection.isClosed()) {
                JOptionPane.showMessageDialog(frame, "Database connection is not available");
                return;
            }

            PreparedStatement ps = connection.prepareStatement(
                    "DELETE FROM Employee WHERE Code=?");
            ps.setString(1, codeField.getText());
            int deleted = ps.executeUpdate();
            String msg = (deleted > 0) ? "Employee deleted!" : "Employee code not found.";
            JOptionPane.showMessageDialog(frame, msg);
            clearFields();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Delete failed:\n" + e.getMessage());
        }
    }

    private void showEmployees() {
        try {
            if (connection == null || connection.isClosed()) {
                JOptionPane.showMessageDialog(frame, "Database connection is not available");
                return;
            }

            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM Employee ORDER BY Name");

            StringBuilder sb = new StringBuilder("Name\tCode\tDesignation\tSalary\n");
            sb.append("----------------------------------------------------\n");
            while (rs.next()) {
                sb.append(rs.getString("Name")).append("\t")
                  .append(rs.getString("Code")).append("\t")
                  .append(rs.getString("Designation")).append("\t")
                  .append(rs.getDouble("Salary")).append("\n");
            }

            JTextArea area = new JTextArea(sb.toString());
            area.setEditable(false);
            JOptionPane.showMessageDialog(frame, new JScrollPane(area), 
                                          "Employee Records", JOptionPane.INFORMATION_MESSAGE);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Could not load records:\n" + e.getMessage());
        }
    }

    private void clearFields() {
        nameField.setText("");
        codeField.setText("");
        designationField.setText("");
        salaryField.setText("");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(EmployeeDatabaseApp::new);
    }
}