public class MultiThread {
    private static int i=1, k=20;
    private static final Object lock = new Object();
     
    public static void main(String[] args) {
        Thread zero = new Thread(() -> {
            while(i <= k) {
                synchronized(lock) {
                    if(i%3==0) {
                        System.out.println("Remainder 0 : " + i++);
                        lock.notify();
                    }
                    else {
                        try {
                            lock.wait();
                        } catch (InterruptedException e) {
                            Thread.currentThread().interrupt();
                            System.out.println("Remainder 0 Thread Interrupted!");
                        }
                    }
                }
            }
        });

        Thread one = new Thread(() -> {
            while(i<=k) {
                synchronized(lock) {
                    if(i%3 == 1) {
                        System.out.println("Remainder 1 : " + i++);
                        lock.notify();
                    }
                    else {
                        try {
                            lock.wait();
                        } catch (Exception e) {
                            Thread.currentThread().interrupt();
                            System.out.println("Remainder 1 is Interrupted!");
                        }
                    }
                }
            }
        });

        Thread two = new Thread(() -> {
            while(i<=k) {
                synchronized(lock) {
                    if(i%3 == 2) {
                        System.out.println("Remainder 2 : " + i++);
                        lock.notify();
                    }
                    else {
                        try {
                            lock.wait();
                        } catch (InterruptedException e) {
                            Thread.currentThread().interrupt();
                            System.out.println("Remainder 2 is Interrupted!");
                        }
                    }
                }
            }
        });

        zero.start();
        one.start();
        two.start();

        try {
            zero.join();
            one.join();
            two.join();
        } catch (InterruptedException e) {
            System.out.println("Main Thread Interrupted!");
        }

        System.out.println("Finished Printing 1 to 20");
    }
}
