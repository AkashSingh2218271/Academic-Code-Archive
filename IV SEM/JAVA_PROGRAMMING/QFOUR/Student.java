package QFOUR;

import java.util.Scanner;

public class Student {
    static String name;
    static int rollNum;
    static String section;
    static float marks[] = new float[3];
    static float avg;

    Student () {
        avg = 0.0f;
    }

    // Setter method
    public static void setInfo(String nm, String sec, int roll, float m[]) {
        name = nm;
        section = sec;
        rollNum = roll;
        for (int i = 0; i < marks.length; i++) {
            marks[i] = m[i];
        }
    }

    // Getter method
    public static void getInfo() {
        System.out.println("\nStudent details");
        System.out.println("Student name is " + name);
        System.out.println("Student section is " + section);
        System.out.println("Student roll number is " + rollNum);
        for (int i = 0; i < marks.length; i++) {
            System.out.println("Student subject " + (i+1) + " marks are " + marks[i]);   
        }
    }

    // Method to calculate average
    public static float average() {
        for (int i = 0; i < marks.length; i++) {
            avg += marks[i];
        }
        return avg / marks.length;
    }


    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter student name : ");
        String name = sc.nextLine();
        System.out.print("Enter student section : ");
        String sec = sc.nextLine();
        System.out.print("Enter student roll number : ");
        int rollNum = sc.nextInt();
        float marks[] = new float[3];
        for (int i = 0; i < marks.length; i++) {
            System.out.print("Enter marks of subject " + (i + 1) + " : ");
             marks[i] = sc.nextFloat();
        }
        
        setInfo(name, sec, rollNum, marks);
        getInfo();
        System.out.println("Average marks of all subject is " + average());
        sc.close();
    }
}
