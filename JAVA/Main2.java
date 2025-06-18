class mr implements Runnable {
    public void run() {
        System.out.println("Thread is running implements runnable");
    }
}

public class Main2 {
    public static void main(String[] args) {
        Thread t = new Thread(new mr());
        t.start();
    }
}
