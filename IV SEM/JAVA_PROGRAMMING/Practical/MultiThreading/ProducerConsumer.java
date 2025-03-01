package Practical.MultiThreading;

class PC {
    int arr[] = new int[5];
    boolean b = false;
    public void producer() throws Exception{
        int value = 0;
        
                while (true) {
                    synchronized(this) {
                        while ( b == true) {
                            wait();
                        }
                        int i = 0;
                        System.out.println("Producer going to proudce");
                        System.out.println("Item produced " + (++value));
                        if (i == arr.length) {
                            break;
                        }
                        arr[i] = value;
                        notify();
                        b = true;
                        Thread.sleep(500);
                }
        }
    }

    public void consumer() throws Exception{
                while (true) {
                    synchronized(this) {
                        while (b == false) {
                        wait();
                        }
                    int i = 0;
                    System.out.println("Consumer going to consume...");
                    if (i == arr.length) {
                        break;
                    }
                    System.out.println("Item consumed " + arr[i++]);
                    notify();
                    b = false;
                    Thread.sleep(500);
                }
        }
    }
}

class AThread extends Thread {
    PC p;
    AThread(PC p) {
        this.p = p;
    }
    public void run() {
        try {
            p.producer();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}

class BThread extends Thread {
    PC c;
    BThread(PC c) {
        this.c = c;
    }
    public void run() {
        try {
            c.consumer();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}

public class ProducerConsumer {
    public static void main(String args[]) {
        PC pc = new PC();
        AThread at = new AThread(pc);
        at.start();
        BThread bt = new BThread(pc);
        bt.start();
    }
}
