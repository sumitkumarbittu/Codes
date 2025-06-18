import java.io.IOException;

public class Example {
    static void myMethod() throws IOException {
        throw new IOException("IO error occurred");
    }

    public static void main(String[] args) {
        try {
            myMethod();
        } catch (IOException e) {
            System.out.println("Exception caught: " + e);
        }
    }
}
