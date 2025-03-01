package Practical.ExceptionHandling;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.io.IOException;

public class checkedAndUnchecked {
    
    public static int division(int a, int b) {
        return a / b;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.println("Enter value of a and b respectively : ");
            int a = sc.nextInt();
            int b = sc.nextInt();
            int ans = division(a, b);
            System.out.println(a + " divide by " + b + " is " + ans);
        } catch (ArithmeticException e) {
            System.out.println("Caught an unchecked exception : " + e.getMessage());
        } 

        try {
            FileReader f = new FileReader("demo.txt");
            System.out.println(f.read());
            f.close();
        } catch (FileNotFoundException e) {
            System.out.println("Caught a checked exception " + e.getMessage());
        } catch (IOException e) {
            System.out.println("IOException " + e.getMessage());
        } finally {
            sc.close();
        }
    }
    
}