import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class VowelCounter extends JFrame {
    private JTextField inputField;
    private JTextField resultField;
    
    public VowelCounter() {
        // Set up the frame
        setTitle("Vowel Counter");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        
        // Create panel for input components
        JPanel inputPanel = new JPanel(new GridLayout(2, 2, 5, 5));
        
        // Input field
        inputPanel.add(new JLabel("Enter a string:"));
        inputField = new JTextField();
        inputPanel.add(inputField);
        
        // Result field
        inputPanel.add(new JLabel("Vowel count:"));
        resultField = new JTextField();
        resultField.setEditable(false);
        inputPanel.add(resultField);
        
        add(inputPanel, BorderLayout.CENTER);
        
        // Create panel for buttons
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 10));
        
        // CountVowel button
        JButton countButton = new JButton("CountVowel");
        countButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                countVowels();
            }
        });
        buttonPanel.add(countButton);
        
        // Reset button
        JButton resetButton = new JButton("Reset");
        resetButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                resetFields();
            }
        });
        buttonPanel.add(resetButton);
        
        // Exit button
        JButton exitButton = new JButton("Exit");
        exitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                exitApp();
            }
        });
        buttonPanel.add(exitButton);
        
        add(buttonPanel, BorderLayout.SOUTH);
    }
    
    private void countVowels() {
        String input = inputField.getText();
        int count = 0;
        String vowels = "aeiouAEIOU";
        
        for (int i = 0; i < input.length(); i++) {
            if (vowels.indexOf(input.charAt(i)) != -1) {
                count++;
            }
        }
        
        resultField.setText(Integer.toString(count));
    }
    
    private void resetFields() {
        inputField.setText("");
        resultField.setText("");
    }
    
    private void exitApp() {
        int confirm = JOptionPane.showConfirmDialog(
            this, 
            "Are you sure you want to exit?", 
            "Exit", 
            JOptionPane.YES_NO_OPTION
        );
        
        if (confirm == JOptionPane.YES_OPTION) {
            System.exit(0);
        }
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new VowelCounter().setVisible(true);
            }
        });
    }
}