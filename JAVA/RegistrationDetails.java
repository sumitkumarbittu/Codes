import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class RegistrationDetails extends JFrame {
    private JTextField nameField;
    private JRadioButton maleRadio;
    private JRadioButton femaleRadio;
    private JComboBox<String> countryCombo;
    private JTextArea resultArea;

    setTitle("Registration Form");
    setSize(400, 300);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLayout(new BorderLayout(10, 10));
    
    JPanel formPanel = new JPanel(new GridLayout(4, 2, 5, 5));

    formPanel.add(new JLabel("Name"));
    nameField = new JTextField();
    formPanel.add(nameField);

    


    public static void main(String[] args) {

    }
}
