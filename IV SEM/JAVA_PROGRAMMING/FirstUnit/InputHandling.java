package FirstUnit;

//package JAVA_PROGRAMMING.FirstUnit;
import java.util.Scanner;

public class InputHandling {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any number :");
        int x = sc.nextInt();
        System.out.println("Enter any float number :");
        float f = sc.nextFloat();
        System.out.println("Enter any character :");
        char c = sc.next().charAt(0);
        System.out.println("Enter any string value :");
        String str = sc.nextLine();
        System.out.println("value of integer x is : " + x);
        System.out.println("value of float f is : " + f);
        System.out.println("value of string str is : " + str);
        System.out.println("value of char c is : " + c);
        sc.close();
    }
}
