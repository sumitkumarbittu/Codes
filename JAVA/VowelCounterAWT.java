import java.awt.*;
import java.awt.event.*;

public class VowelCounterAWT extends Frame {
    private TextField inputField;
    private TextField resultField;
    private Button countButton;
    private Button resetButton;
    private Button exitButton;

    public VowelCounterAWT() {
        // Set up the frame
        setTitle("Vowel Counter (AWT)");
        setSize(400, 200);
        setLayout(new GridLayout(4, 2, 10, 10));

        // Create components
        Label inputLabel = new Label("Enter a string:");
        inputField = new TextField();
        Label resultLabel = new Label("Vowel count:");
        resultField = new TextField();
        resultField.setEditable(false);
        
        countButton = new Button("CountVowel");
        resetButton = new Button("Reset");
        exitButton = new Button("Exit");

        // Add components to the frame
        add(inputLabel);
        add(inputField);
        add(resultLabel);
        add(resultField);
        add(countButton);
        add(resetButton);
        add(exitButton);

        // Add action listeners
        countButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                countVowels();
            }
        });

        resetButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                inputField.setText("");
                resultField.setText("");
            }
        });

        exitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        // Handle window closing
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    private void countVowels() {
        String text = inputField.getText().toLowerCase();
        int vowelCount = 0;
        
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelCount++;
            }
        }
        
        resultField.setText(Integer.toString(vowelCount));
    }

    public static void main(String[] args) {
        VowelCounterAWT counter = new VowelCounterAWT();
        counter.setVisible(true);
    }
}