import java.io.*;

public class Copy {
    public static void main(String args[]) throws IOException {
        FileInputStream fIS1 = new FileInputStream("source.txt");
        FileOutputStream fOS = new FileOutputStream("dest.txt");
        int input;
        while ((input = fIS1.read()) != -1) {
            fOS.write(input);
        }
        System.out.println("Data copied successfully");
        fIS1.close();
        fOS.close();
    }
}
