import java.lang.*;
import java.util.*;

public class WrapCls {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        s.nextLine();
        String b = s.nextLine();
        Integer c = Integer.valueOf(b);

        int d = c.intValue();

        System.out.println(d+3);

        Wc e = new Wc();

        e.display();

        s.close();
    }

    
}

class Wc {
    void display() {
        System.out.println("Hello!");
    }
}