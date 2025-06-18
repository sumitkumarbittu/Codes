import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class Vowel {
    public static void main(String[] args) {
        //window
        JFrame frame = new JFrame("Vowel");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //components
        JLabel inputLabel = new JLabel("String : ");
        JTextArea inputBox = new JTextArea(5, 30);
        inputBox.setLineWrap(true);
        JTextArea outputBox = new JTextArea("No of Vowels : ", 5, 30);
        outputBox.setEditable(false);
        JButton countButton = new JButton("Count");

        //Box Scroll
        JScrollPane inputScrollPane = new JScrollPane(inputBox);
        JScrollPane outputScrollPane = new JScrollPane(outputBox);

        //layout
        frame.setLayout(new FlowLayout());

        //components to window
        frame.add(inputLabel);
        frame.add(inputScrollPane);
        frame.add(outputScrollPane);
        frame.add(countButton);

        //count button
        countButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String text = inputBox.getText();
                int vowels = 0;

                text = text.toLowerCase();

                for(int i=0;i<text.length();i++) {
                    char c = text.charAt(i);
                    if("aeiou".indexOf(c) != -1)
                        vowels++;
                }

                outputBox.setText(String.valueOf("No of Vowels : "+vowels));
            }
        });



        //visible
        frame.setVisible(true);

    }
}
