package FirstUnit;

//package JAVA_PROGRAMMING.FirstUnit;

import java.util.Scanner;

/**
 * StringDiff
 */
public class StringDiff {
    public static void diffStr(String s1, char s2[], String s3) {
        System.out.println("String one is " + s1);
        System.out.println("String one length is " + s1.length());
        System.out.print("String two is ");
        for (int i = 0; i < s2.length; i++) {
            System.out.print(s2[i]);
        }
        System.out.println();
        System.out.println("String two length is " + s2.length);
        System.out.println("String three is " + s3);
        System.out.println("String three length is " + s3.length());
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter string one : ");
        String s1 = sc.nextLine();
        System.out.print("Enter string two : ");
        char s2[] = new char[10];
        s2 = sc.nextLine().toCharArray();
        System.out.print("Enter string three : ");
        String s3 = new String();
        s3 = sc.nextLine();
        String s4 = new String(s2);
        diffStr(s1, s2, s3);
        System.out.print("Enter string five : ");
        String s5 = sc.nextLine();
        System.out.println("String four from string two is " + s4);
        System.out.println("String fout length is " + s4.length());
        System.out.println("All string after concatination is " + s1.concat(" ").concat(s4).concat(" ").concat(s3));
        System.out.println("String s1 and s2 are equal " + s1.equals(s3));
        System.out.println("String s1 and s5 are equal without case " + s1.equalsIgnoreCase(s5));
        sc.close();
    }
}