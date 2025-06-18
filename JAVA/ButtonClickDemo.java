import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ButtonClickDemo {

    public static void main(String[] args) {
        // Create the main frame
        JFrame frame = new JFrame("Button Click Demo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLayout(new java.awt.FlowLayout());

        // Create a button
        JButton button = new JButton("Click Me!");
        
        // Create a label to display the message
        JLabel messageLabel = new JLabel("Waiting for button click...");
        
        // Add action listener to the button
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                messageLabel.setText("Button was clicked!");
            }
        });

        // Add components to the frame
        frame.add(button);
        frame.add(messageLabel);
        
        // Display the frame
        frame.setVisible(true);
    }
}