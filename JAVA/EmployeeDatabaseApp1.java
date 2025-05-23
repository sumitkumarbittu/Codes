//-- Active: 1747936853231@@localhost@3306@mysql
import java.awt.*;
import java.lang.String;
import java.sql.*;
import javax.swing.*;

public class EmployeeDatabaseApp1 {
    private JFrame frame;
    private JTextField nameField, codeField, designationField, salaryField;
    private Connection connection;

    public EmployeeDatabaseApp1() {
        setupDatabase();
        buildGUI();
    }

    private void setupDatabase() {
        Connection connection = null;
        try {
            // 1. Load driver (newer JDBC versions may not need this)
            Class.forName("com.mysql.cj.jdbc.Driver");
            
            // 2. Connect with additional parameters
            String url = "jdbc:mysql://localhost:3306/db1";
            String user = "root";
            String password = "sumitkumarbittu";
            
            System.out.println("Attempting to connect to: " + url);
            connection = DriverManager.getConnection(url, user, password);
            System.out.println("Connection successful!");
    
            // 3. Create table
            try (Statement stmt = connection.createStatement()) {
                stmt.executeUpdate("CREATE TABLE IF NOT EXISTS Employee (" +
                    "Name VARCHAR(50), " +
                    "Code VARCHAR(20), " +
                    "Designation VARCHAR(50), " +
                    "Salary DECIMAL(10,2))");
                System.out.println("Table created/verified");
            }
            
        } catch (ClassNotFoundException e) {
            System.err.println("MySQL Driver missing! Add mysql-connector-java.jar to your classpath.");
            e.printStackTrace();
        } catch (SQLException e) {
            System.err.println("SQL Error:");
            System.err.println("SQL State: " + e.getSQLState());
            System.err.println("Error Code: " + e.getErrorCode());
            System.err.println("Message: " + e.getMessage());
            e.printStackTrace();
        } finally {
            if (connection != null) {
                try { 
                    connection.close(); 
                    System.out.println("Connection closed");
                } catch (SQLException e) { 
                    System.err.println("Failed to close connection");
                }
            }
        }
    }

    private void buildGUI() {
        frame = new JFrame("Employee Entry Form");
        frame.setSize(400, 300);
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
            PreparedStatement ps = connection.prepareStatement(
                    "INSERT INTO Employee (Name, Code, Designation, Salary) VALUES (?, ?, ?, ?)");
            ps.setString(1, nameField.getText());
            ps.setString(2, codeField.getText());
            ps.setString(3, designationField.getText());
            ps.setDouble(4, Double.parseDouble(salaryField.getText()));
            ps.executeUpdate();
            JOptionPane.showMessageDialog(frame, "Employee saved!");
            clearFields();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Could not save. Check your input.");
        }
    }

    private void updateEmployee() {
        try {
            PreparedStatement ps = connection.prepareStatement(
                    "UPDATE Employee SET Name=?, Designation=?, Salary=? WHERE Code=?");
            ps.setString(1, nameField.getText());
            ps.setString(2, designationField.getText());
            ps.setDouble(3, Double.parseDouble(salaryField.getText()));
            ps.setString(4, codeField.getText());
            int updated = ps.executeUpdate();
            String msg = (updated > 0) ? "Updated!" : "Code not found.";
            JOptionPane.showMessageDialog(frame, msg);
            clearFields();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Update failed.");
        }
    }

    private void deleteEmployee() {
        try {
            PreparedStatement ps = connection.prepareStatement(
                    "DELETE FROM Employee WHERE Code=?");
            ps.setString(1, codeField.getText());
            int deleted = ps.executeUpdate();
            String msg = (deleted > 0) ? "Deleted!" : "Code not found.";
            JOptionPane.showMessageDialog(frame, msg);
            clearFields();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Delete failed.");
        }
    }

    private void showEmployees() {
        try {
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM Employee");

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
        } catch (Exception e) {
            JOptionPane.showMessageDialog(frame, "Could not load records.");
        }
    }

    private void clearFields() {
        nameField.setText("");
        codeField.setText("");
        designationField.setText("");
        salaryField.setText("");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(EmployeeDatabaseApp1::new);
    }
}
