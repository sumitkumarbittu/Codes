import javax.swing.*;
import java.awt.*;

public class DrawingPanel extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        
        // Set rendering hints for better quality
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, 
                           RenderingHints.VALUE_ANTIALIAS_ON);
        
        // Draw shapes
        g2d.setColor(Color.RED);
        g2d.fillOval(50, 50, 100, 100);
        
        g2d.setColor(Color.BLUE);
        g2d.drawRect(200, 50, 100, 100);
        
        // Draw text
        g2d.setColor(Color.BLACK);
        g2d.setFont(new Font("Arial", Font.BOLD, 16));
        g2d.drawString("Hello Swing Graphics!", 50, 200);
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Graphics Demo");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.add(new DrawingPanel());
            frame.setSize(400, 300);
            frame.setVisible(true);
        });
    }
}