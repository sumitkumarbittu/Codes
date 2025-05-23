import java.nio.file.Files;
import java.nio.file.Paths;

public class d {
    public static void main(String[] args) {
        String a = new String(Files.readAllBytes(Paths.get("/Users/inflasher_b2/Documents/GitHub/Codes/JAVA/password.txt"))).trim();

        System.out.println(a);
    }
}
