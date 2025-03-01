package QONE;

import java.util.Scanner;

public class Student {
    
    String name;
    int rollNum;
    String section;
    float marks[] = new float[3];
    float avg;

    Student () {
        this.avg = 0.0f;
    }

    // Setter method
    public  void setInfo(String nm, String sec, int roll, float m[]) {
        name = nm;
        section = sec;
        rollNum = roll;
        for (int i = 0; i < marks.length; i++) {
            marks[i] = m[i];
        }
    }

    // Getter method
    public void getInfo() {
        System.out.println("\nStudent details");
        System.out.println("Student name is " + name);
        System.out.println("Student section is " + section);
        System.out.println("Student roll number is " + rollNum);
        for (int i = 0; i < marks.length; i++) {
            System.out.println("Student subject " + (i+1) + "  marks are " + marks[i]);   
        }
    }

    // Method to calculate average
    public float average() {
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
        
        Student s = new Student();
        s.setInfo(name, sec, rollNum, marks);
        s.getInfo();
        System.out.println("Average marks of all subject is " + s.average());
        sc.close();
    }

}
