import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JRadioButton;

public class ButtonClickDemo2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Button Click");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        JLabel label = new JLabel("Click Button!");
        JButton button = new JButton("Button");
        
        JRadioButton male = new JRadioButton("Male");
        JRadioButton female = new JRadioButton("Female");
        ButtonGroup gender = new ButtonGroup();
        
        JLabel sex = new JLabel("Gender : ");
        
        gender.add(male);
        gender.add(female);

        
        JComboBox<String> color = new JComboBox<>();
        color.addItem("Red");
        color.addItem("Yellow");
        color.addItem("Green");


        frame.add(label);
        frame.add(button);
        frame.add(male);
        frame.add(female);
        frame.add(sex);
        frame.add(color);

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                label.setText("Button was Clicked");

                if(male.isSelected())
                    sex.setText("Gender is Male & Color is " + color.getSelectedItem());
                else if(female.isSelected()) 
                    sex.setText("Gender is female & Color is " + color.getSelectedItem());
                else
                    sex.setText("Select a Gender & Color is " + color.getSelectedItem());
            }
        });

        frame.setVisible(true);
    }
}
