package FirstUnit;

//package JAVA_PROGRAMMING.FirstUnit;

import java.util.Scanner;

public class AgeVerification {
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your age : ");
        int age = sc.nextInt();
        UserDetails us = new UserDetails();
        us.getData(age);
        us.ageVerify();
        us.putData();
        sc.close();
    }
}

class UserDetails {
    int age;
    public
    void getData(int age) {
        this.age = age;
    }
    void ageVerify() {
        if(age >= 120 || age < 0) {
            System.out.println("error wrong age has been inputed.");
        } else if (age >= 0 && age <= 12) {
            System.out.println("You are a child.");
        } else if (age >= 13 && age <= 19) {
            System.out.println("You are a teenager.");
        } else if (age >= 20 && age <= 59) {
            System.out.println("You are an adult.");
        } else if (age >= 60 && age < 120) {
            System.out.println("You are an senior.");
        } 
    }
    void putData() {
        System.out.println("Age is = " + age);
    }
}
