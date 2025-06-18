import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class ButtonClickDemo1 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Button Click!");
        frame.setSize(400,300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        JButton button = new JButton("Button");
        JLabel label = new JLabel("Click the button");

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                label.setText("Button was Clicked");
            }
        });

        frame.add(label);
        frame.add(button);

        frame.setVisible(true);
    }
}
