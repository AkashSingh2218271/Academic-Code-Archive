package Practical.MultiThreading;
/**
 * ThreadTest
 */
class MyThread extends Thread {
    public void run() {
        int count = 1;
        while (count != 100) {
            System.out.println((count++) + " My Thread");            
        }
    }
}

public class ThreadTest {

    public static void main(String args[]) {
        MyThread t = new MyThread();
        t.start();
        int count = 1;
        while (count != 100) {
            System.out.println((count++) + " Main");
            Thread.yield();            
        }
    }
}