import java.awt.*;

public class AWTExample {
    public static void main(String[] args) {
        Frame frame = new Frame("AWT Window");
        Button btn = new Button("Click Me");
        frame.add(btn);
        frame.setSize(300, 200);
        frame.setVisible(true);
    }
}