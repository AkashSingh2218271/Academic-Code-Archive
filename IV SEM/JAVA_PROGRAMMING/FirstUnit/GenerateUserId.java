package FirstUnit;

//package JAVA_PROGRAMMING.FirstUnit;

import java.util.Scanner;

public class GenerateUserId {

    // static int isDigit(int pin, int n) {
    //     int x = pin, i = 0;
    //     while (i != n) {
    //         pin = x % 10;
    //         x /= 10;
    //         i++;
    //     }
    //     System.out.println("d = " + pin);
    //     return pin;
    // }
    
    // static int revNum(int pin) {
    //     int n = pin;
    //     pin = 0;
    //     int i = 0, d;
    //     while (n != 0) {
    //         d = n % 10;
    //         n /= 10;
    //         pin = pin * 10 + d;
    //     }
    //     return pin;
    // }
    static void genId(String fName, String lName, String pin, int n) {
        int len1 = fName.length();
        int len2 = lName.length();
        String id = "";
        if(len1 == len2) {
            if(fName.compareTo(lName) > 0) {
                char ch = lName.charAt(len2-1);
                id += ch;
                id += fName;
                id += pin.charAt(n - 1);
                id += pin.charAt(pin.length() - n);
                id = toogleCase(id);
            } else {
                char ch = fName.charAt(len2-1);
                id += ch;
                id += lName;
                id += pin.charAt(n - 1);
                id += pin.charAt(pin.length() - n);
                id = toogleCase(id);
            }
        } else if (len1 > len2) {
            char ch = lName.charAt(len2-1);
            id += ch;
            id += fName;
            id += pin.charAt(n - 1);
            id += pin.charAt(pin.length() - n);
            id = toogleCase(id);
            //id += isDigit(pin, n);
            //pin = revNum(pin);
            //id += isDigit(pin, n);
        } else {
            char ch = fName.charAt(len2-1);
            id += ch;
            id += lName;
            id += pin.charAt(n - 1);
            id += pin.charAt(pin.length() - n);
            id = toogleCase(id);
        }
        System.out.println("User id is " + id);
    }
    
    static String toogleCase(String id) {
        String s = "";
        //System.out.println("ch1User id is " + id);
        for(int i = 0; i < id.length(); i++) {
            char ch = id.charAt(i);
            if('A' <= ch && ch <= 'Z') {
                s += (char) (ch + 32);
            } else if ('a' <= ch && ch <= 'z') {
                s += (char) (ch - 32);
            } else {
                s += ch;
            }
        }
        id = s;
        //System.out.println("ch2User id is " + id);
        return id;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        //int pin[] = new int[10];
        //System.out.println(pin.length);
        System.out.print("Enter your first name : ");
        String fName = sc.nextLine();
        System.out.print("Enter your last name : ");
        String lName = sc.nextLine();
        System.out.print("Enter your pin : ");
        int pin = sc.nextInt();
        String p = String.valueOf(pin);
        // for(int i = 0; i < pin.length; i++) {
        //    pin[i] = sc.nextInt();   
        // }
        System.out.print("Enter value of N : ");
        int N = sc.nextInt();
        genId(fName, lName, p, N);
        sc.close();
    }
}
