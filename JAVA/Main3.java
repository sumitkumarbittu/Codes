//import java.io.*;

class Counter {
    static int x = 0, y = 0;

    private final Object lock = new Object();

    public int incrementx() throws InterruptedException {
        synchronized(lock) {
            if(y < 5) lock.wait();
            lock.notify();
            return ++x;
        }
    }

    public int incrementy() {
        synchronized(lock) {
            /*try {
                if(x < 5) lock.wait();
            } catch (InterruptedException e) {
                //
            }*/
            lock.notify();
            return ++y;
        }
    }
}

public class Main3 {
    public static void main(String[] args) throws InterruptedException {
        Counter c = new Counter();

        Thread t1 = new Thread(() -> {
            for (int i=0; i < 10; i++) {
                
                try {
                    System.out.println("x : "+ c.incrementx());
                } catch (InterruptedException e) {

                }

                try {
                    Thread.sleep(0);
                } catch (Exception e) {
                    //exception handling
                }
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i=0; i < 10; i++) {
                System.out.println("y : " +  c.incrementy());
            } 
        });
        
        t1.start();
        t2.start();
        
        t1.join();
        t2.join();

        System.out.println("Both threads completed");
        
    }
}