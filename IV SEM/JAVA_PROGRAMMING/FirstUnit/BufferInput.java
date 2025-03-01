package FirstUnit;

//package JAVA_PROGRAMMING.FirstUnit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BufferInput {
    public static void main(String args[]) throws IOException{
        int x;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter value of x :");
        x = Integer.parseInt(br.readLine());

        System.out.println(x);
    }
}
