import java.awt.*;
import java.lang.String;
import java.sql.*;
import java.util.ArrayList;
import javax.swing.*;

public class EmployeeDatabaseApp2 {
    private JFrame frame;
    private JTextField nameField, codeField, designationField, salaryField;
    private JButton submitButton, saveButton, updateButton, deleteButton, resetButton, exitButton;
    private Connection connection;
    
    public EmployeeDatabaseApp2() {
        initializeDatabase();
        createGUI();
    }
    
    private void initializeDatabase() {
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
            

            // Create Employee table if it doesn't exist
            Statement stmt = connection.createStatement();
            stmt.executeUpdate("CREATE TABLE Employee (" +
                              "Name VARCHAR(50), " +
                              "Code VARCHAR(20), " +
                              "Designation VARCHAR(50), " +
                              "Salary DECIMAL(10,2))");
            stmt.close();
        } catch (ClassNotFoundException e) {
            JOptionPane.showMessageDialog(null, "JDBC Driver not found!");
            System.exit(1);
        } catch (SQLException e) {
            // Table already exists - we can ignore this error
            if (!e.getSQLState().equals("X0Y32")) {
                e.printStackTrace();
            }
        }
    }
    
    private void createGUI() {
        frame = new JFrame("Employee Entry Form");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);
        frame.setLayout(new BorderLayout());
        
        // Form panel
        JPanel formPanel = new JPanel(new GridLayout(5, 2, 5, 5));
        formPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        
        formPanel.add(new JLabel("NAME"));
        nameField = new JTextField();
        formPanel.add(nameField);
        
        formPanel.add(new JLabel("CODE"));
        codeField = new JTextField();
        formPanel.add(codeField);
        
        formPanel.add(new JLabel("DESIGNATION"));
        designationField = new JTextField();
        formPanel.add(designationField);
        
        formPanel.add(new JLabel("SALARY"));
        salaryField = new JTextField();
        formPanel.add(salaryField);
        
        // Button panel
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 10));
        submitButton = new JButton("Submit");
        saveButton = new JButton("Save");
        updateButton = new JButton("Update");
        deleteButton = new JButton("Delete");
        resetButton = new JButton("Reset");
        exitButton = new JButton("Exit");
        
        buttonPanel.add(submitButton);
        buttonPanel.add(saveButton);
        buttonPanel.add(updateButton);
        buttonPanel.add(deleteButton);
        buttonPanel.add(resetButton);
        buttonPanel.add(exitButton);
        
        // Add panels to frame
        frame.add(formPanel, BorderLayout.CENTER);
        frame.add(buttonPanel, BorderLayout.SOUTH);
        
        // Add action listeners
        submitButton.addActionListener(e -> showAllRecords());
        saveButton.addActionListener(e -> saveRecord());
        updateButton.addActionListener(e -> updateRecord());
        deleteButton.addActionListener(e -> deleteRecord());
        resetButton.addActionListener(e -> resetForm());
        exitButton.addActionListener(e -> System.exit(0));
        
        frame.setVisible(true);
    }
    
    private void saveRecord() {
        try {
            String name = nameField.getText();
            String code = codeField.getText();
            String designation = designationField.getText();
            String salaryText = salaryField.getText();
            
            if (name.isEmpty() || code.isEmpty() || designation.isEmpty() || salaryText.isEmpty()) {
                JOptionPane.showMessageDialog(frame, "Please fill all fields!", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            
            double salary;
            try {
                salary = Double.parseDouble(salaryText);
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(frame, "Invalid salary format!", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            
            PreparedStatement pstmt = connection.prepareStatement(
                "INSERT INTO Employee (Name, Code, Designation, Salary) VALUES (?, ?, ?, ?)");
            pstmt.setString(1, name);
            pstmt.setString(2, code);
            pstmt.setString(3, designation);
            pstmt.setDouble(4, salary);
            
            pstmt.executeUpdate();
            pstmt.close();
            
            JOptionPane.showMessageDialog(frame, "Record Saved", "Message", JOptionPane.INFORMATION_MESSAGE);
            resetForm();
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Error saving record: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    private void updateRecord() {
        try {
            String code = codeField.getText();
            if (code.isEmpty()) {
                JOptionPane.showMessageDialog(frame, "Please enter employee code to update!", 
                    "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            
            String name = nameField.getText();
            String designation = designationField.getText();
            String salaryText = salaryField.getText();
            
            if (name.isEmpty() || designation.isEmpty() || salaryText.isEmpty()) {
                JOptionPane.showMessageDialog(frame, "Please fill all fields!", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            
            double salary;
            try {
                salary = Double.parseDouble(salaryText);
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(frame, "Invalid salary format!", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            
            PreparedStatement pstmt = connection.prepareStatement(
                "UPDATE Employee SET Name=?, Designation=?, Salary=? WHERE Code=?");
            pstmt.setString(1, name);
            pstmt.setString(2, designation);
            pstmt.setDouble(3, salary);
            pstmt.setString(4, code);
            
            int rowsAffected = pstmt.executeUpdate();
            pstmt.close();
            
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(frame, "Record Updated", "Message", JOptionPane.INFORMATION_MESSAGE);
                resetForm();
            } else {
                JOptionPane.showMessageDialog(frame, "No record found with code: " + code, 
                    "Error", JOptionPane.ERROR_MESSAGE);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Error updating record: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    private void deleteRecord() {
        try {
            String code = codeField.getText();
            if (code.isEmpty()) {
                JOptionPane.showMessageDialog(frame, "Please enter employee code to delete!", 
                    "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            
            PreparedStatement pstmt = connection.prepareStatement(
                "DELETE FROM Employee WHERE Code=?");
            pstmt.setString(1, code);
            
            int rowsAffected = pstmt.executeUpdate();
            pstmt.close();
            
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(frame, "Record Deleted", "Message", JOptionPane.INFORMATION_MESSAGE);
                resetForm();
            } else {
                JOptionPane.showMessageDialog(frame, "No record found with code: " + code, 
                    "Error", JOptionPane.ERROR_MESSAGE);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Error deleting record: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    private void resetForm() {
        nameField.setText("");
        codeField.setText("");
        designationField.setText("");
        salaryField.setText("");
    }
    
    private void showAllRecords() {
        try {
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM Employee");
            
            ArrayList<String> records = new ArrayList<>();
            records.add("Employee Records:");
            records.add("---");
            records.add(String.format("%-10s %-10s %-15s %-10s", "Name", "Code", "Designation", "Salary"));
            records.add("---");
            
            while (rs.next()) {
                String name = rs.getString("Name");
                String code = rs.getString("Code");
                String designation = rs.getString("Designation");
                double salary = rs.getDouble("Salary");
                
                records.add(String.format("%-10s %-10s %-15s %-10.2f", name, code, designation, salary));
            }
            
            rs.close();
            stmt.close();
            
            if (records.size() == 4) { // Only headers
                records.add("No records found");
            }
            
            JTextArea textArea = new JTextArea(String.join("\n", records));
            textArea.setEditable(false);
            JScrollPane scrollPane = new JScrollPane(textArea);
            scrollPane.setPreferredSize(new Dimension(400, 300));
            
            JOptionPane.showMessageDialog(frame, scrollPane, "Employee Records", JOptionPane.INFORMATION_MESSAGE);
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Error retrieving records: " + e.getMessage(), 
                "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new EmployeeDatabaseApp2());
    }
}
