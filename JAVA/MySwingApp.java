import javax.swing.*;

public class MySwingApp {
    public static void main(String[] args) {
        // Create the frame on the event dispatch thread
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("My Swing App");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(400, 300);
            
            // Add components here
            
            frame.setVisible(true);
        });
    }
}