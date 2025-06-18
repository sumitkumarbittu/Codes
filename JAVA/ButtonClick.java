
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JRadioButton;

public class ButtonClick {
    public static void main(String[] args) {
        //window
        JFrame frame = new JFrame("Button Example");
        frame.setSize(400,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //components
        JButton button = new JButton("Click Me");
        JLabel label = new JLabel("Button not clicked");

        JRadioButton blueRadio = new JRadioButton("Blue");
        JRadioButton redRadio = new JRadioButton("Red");
        ButtonGroup color = new ButtonGroup();
        color.add(blueRadio);
        color.add(redRadio);

        JComboBox<String> combo = new JComboBox<>(new String[] {"Happy", "Excited", "Attentive"});

        JTable print = 

        //layout
        frame.setLayout(new GridLayout(4,2,5,5));

        //component to window
        frame.add(button);
        frame.add(label);
        frame.add(blueRadio);
        frame.add(redRadio);
        frame.add(combo);
        frame.add(print);

        //click button
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                label.setText("Hello World");
            }
        });

        //print button
        print.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {

            }
        });

        frame.setColor(Color.RED);
        //visible
        frame.setVisible(true);
    }
}
