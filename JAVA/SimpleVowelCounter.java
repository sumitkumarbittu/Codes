import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class SimpleVowelCounter {

    public static void main(String[] args) {
        // Create the main window
        JFrame frame = new JFrame("Vowel Counter");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Create components
        JLabel instructionLabel = new JLabel("Enter some text:");
        JTextArea textArea = new JTextArea(5,30);
        JButton countButton = new JButton("Count Vowels");
        JLabel resultLabel = new JLabel("Vowels: 0");
        
        // Make text area scrollable
        JScrollPane scrollPane = new JScrollPane(textArea);
        
        // Set layout (simple vertical arrangement)
        frame.setLayout(new java.awt.FlowLayout());
        
        // Add components to window
        frame.add(instructionLabel);
        frame.add(scrollPane);
        frame.add(countButton);
        frame.add(resultLabel);
        
        // Button click action
        countButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String text = textArea.getText();
                int vowels = 0;
                
                // Convert to lowercase to check both cases
                text = text.toLowerCase();
                
                // Count each vowel
                for (int i = 0; i < text.length(); i++) {
                    char c = text.charAt(i);
                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                        vowels++;
                    }
                }
                
                // Show result
                resultLabel.setText("Vowels: " + vowels);
            }
        });
        
        // Make window visible
        frame.setVisible(true);
    }
}