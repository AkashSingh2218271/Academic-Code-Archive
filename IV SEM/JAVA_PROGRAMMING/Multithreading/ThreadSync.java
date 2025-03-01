
/**
 * Sender
 */
class Sender {
    public void Send(String msg) {
        System.out.println("Sending " + msg);
        try {
            Thread.sleep(2000);
        }
        catch (Exception e) {
            System.out.println("Thread Interrputed");
        }
        System.out.println(msg + "sent"); 
    }
}
class ThreadedSend extends Thread{
    private String msg;
    Sender sender;
    ThreadedSend(String m, Sender obj) {
        msg = m;
        sender = obj;
    }

    public void run() {
        synchronized(sender) {
            sender.Send(msg);
        }
    }
}
public class ThreadSync {
    public static void main(String[] args) {
        Sender send = new Sender();
        ThreadedSend s1 = new ThreadedSend("Hi", send);
        ThreadedSend s2 = new ThreadedSend("Bye", send);  
        s1.start();
        s2.start();
        try {
            s1.join();
            s2.join();
        }
        catch (Exception e) {
            System.out.println("Thread Interrputed");
        }    
    }
}