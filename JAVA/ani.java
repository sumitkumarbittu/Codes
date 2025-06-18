public class ani {
    public static void main(String []args) {
        animal a = new Bird();
        animal b = new Dog();

        a.makesound();
        a.move();

        b.makesound();
        b.move();
    }
}

interface animal {
    void makesound();
    void move();
}

class Bird implements animal {
    public void makesound() {
        System.out.println("Chirp");
    }
    public void move() {
        System.out.println("fly");
    }
}

class Dog implements animal {
    public void makesound() {
        System.out.println("Bark");
    }
    public void move() {
        System.out.println("run");
    }
}
