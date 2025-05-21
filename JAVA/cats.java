import java.util.*;

class animal{
    public void makesound() {
        System.out.println("Animal Makes Sound!");
    }
}

class dog extends animal {
    public void makesound() {
        System.out.println("Dog Makes Sound!");
    }
}

class german extends dog {
    public void makesound() {
       System.out.println("German  Makes Sound!");
    }
}

public class cats {
    public static void main(String[] args) {
        animal a = new animal();
        animal b = new dog();
        animal c = new german();

        a.makesound();
        b.makesound();
        c.makesound();
    }
}