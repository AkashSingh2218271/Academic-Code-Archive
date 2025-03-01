package Practical.MultiThreading;
class AkashThread extends Thread{
    public void run() {
        int i = 1;
        while (i < 10) {
            System.out.println((i++) + " good");
        }
    }
}
class CreateThread {
    public static void main(String args[]) {
        AkashThread t = new AkashThread();
        t.start();
        int i = 1;
        while (i < 10) {
            System.out.println((i++) + " morning");
        }
    }
}