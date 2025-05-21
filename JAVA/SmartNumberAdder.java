import java.awt.*;
import java.awt.event.*;

public class SmartNumberAdder extends Frame {
    private TextField firstNumberField, secondNumberField, resultField;
    private Button addButton;

    public SmartNumberAdder() {
        setTitle("Smart Number Adder (AWT)");
        setSize(400, 200);
        setLayout(new GridLayout(4, 2, 10, 10));

        firstNumberField = new TextField();
        secondNumberField = new TextField();
        resultField = new TextField();
        resultField.setEditable(false);
        addButton = new Button("Add");

        add(new Label("First Number:"));
        add(firstNumberField);
        add(new Label("Second Number:"));
        add(secondNumberField);
        add(new Label("Result:"));
        add(resultField);
        add(new Label()); // spacer
        add(addButton);

        addButton.addActionListener(e -> calculateSum());

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose(); // release resources
                System.exit(0);
            }
        });
    }

    private void calculateSum() {
        try {
            double num1 = Double.parseDouble(firstNumberField.getText());
            double num2 = Double.parseDouble(secondNumberField.getText());
            double sum = num1 + num2;

            // Show integer if no decimal part, else show decimal
            resultField.setText((sum == (int) sum) ? String.valueOf((int) sum) : String.valueOf(sum));
        } catch (NumberFormatException ex) {
            resultField.setText("Invalid input!");
        }
    }

    public static void main(String[] args) {
        new SmartNumberAdder().setVisible(true);
    }
}
