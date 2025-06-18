import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RegistrationForm extends JFrame {
    private JTextField nameField;
    private JRadioButton maleRadio, femaleRadio;
    private JComboBox<String> countryCombo;
    private JTextArea resultArea;

    public RegistrationForm() {
        // Set up the frame
        setTitle("Registration Form");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout(10, 10));

        // Create the form panel
        JPanel formPanel = new JPanel(new GridLayout(4, 2, 5, 5));
        
        // Name field
        formPanel.add(new JLabel("Name:"));
        nameField = new JTextField();
        formPanel.add(nameField);
        
        // Gender radio buttons
        formPanel.add(new JLabel("Gender:"));
        JPanel genderPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        maleRadio = new JRadioButton("Male");
        femaleRadio = new JRadioButton("Female");
        ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(maleRadio);
        genderGroup.add(femaleRadio);
        genderPanel.add(maleRadio);
        genderPanel.add(femaleRadio);
        formPanel.add(genderPanel);
        
        // Country combo box
        formPanel.add(new JLabel("Country:"));
        String[] countries = {"India", "USA", "UK"};
        countryCombo = new JComboBox<>(countries);
        formPanel.add(countryCombo);
        
        // Submit button
        formPanel.add(new JLabel(""));
        JButton submitButton = new JButton("Submit");
        formPanel.add(submitButton);
        
        // Result area
        resultArea = new JTextArea();
        resultArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(resultArea);
        
        // Add components to frame
        add(formPanel, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);
        
        // Register ActionListener with the submit button
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showRegistrationDetails();
            }
        });
    }
    
    private void showRegistrationDetails() {
        // Get values from form components
        String name = nameField.getText();
        String gender = maleRadio.isSelected() ? "Male" : 
                        femaleRadio.isSelected() ? "Female" : "Not specified";
        String country = (String) countryCombo.getSelectedItem();
        
        // Display in text area
        String details = "Registration Details:\n" +
                         "Name: " + name + "\n" +
                         "Gender: " + gender + "\n" +
                         "Country: " + country;
        
        resultArea.setText(details);
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new RegistrationForm().setVisible(true);
            }
            
        });
    }
}