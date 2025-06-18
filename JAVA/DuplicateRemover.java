import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedHashSet;
import java.util.Set;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class DuplicateRemover {
    public static void main(String[] args) {
        //window
        JFrame frame = new JFrame("Duplicate Remover");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //components
        JLabel inputLabel = new JLabel("Enter numbers (comma separated): ");
        JTextArea inputBox = new JTextArea(5, 30);
        inputBox.setLineWrap(true);
        JTextArea outputBox = new JTextArea("Result without duplicates: ", 5, 30);
        outputBox.setEditable(false);
        JButton removeButton = new JButton("Remove Duplicates");
        JButton resetButton = new JButton("Reset");

        //Box Scroll
        JScrollPane inputScrollPane = new JScrollPane(inputBox);
        JScrollPane outputScrollPane = new JScrollPane(outputBox);

        //layout
        frame.setLayout(new FlowLayout());

        //components to window
        frame.add(inputLabel);
        frame.add(inputScrollPane);
        frame.add(outputScrollPane);
        frame.add(removeButton);
        frame.add(resetButton);

        //remove duplicates button
        removeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String text = inputBox.getText().trim();
        
                if (text.isEmpty()) {
                    outputBox.setText("Please enter a number first!");
                    return;
                }
        
                StringBuilder result = new StringBuilder();
                Set<Character> seenDigits = new LinkedHashSet<>();
        
                for (char c : text.toCharArray()) {
                    if (Character.isDigit(c)) {
                        if (seenDigits.add(c)) {
                            result.append(c);
                        }
                    } else {
                        outputBox.setText("Please enter digits only!");
                        return;
                    }
                }
         
                outputBox.setText("Result without duplicate digits: " + result.toString());
            }
        });
        

        //reset button
        resetButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                inputBox.setText("");
                outputBox.setText("Result without duplicates: ");
            }
        });

        //visible
        frame.setVisible(true);
    }
}