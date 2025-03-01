package FirstUnit;

//package JAVA_PROGRAMMING.FirstUnit;

import java.util.Scanner;

public class Employee {
    int id;
    int salary;
    String name;
    String companyName;
    void getData(int id, String name, int salary, String companyName) {
        this.name = name;
        this.id = id;
        this.salary = salary;
        this.companyName = companyName;
    }
    void putData() {
        System.out.println("Empolyee details are ->");
        System.out.println("Company Name is " + companyName);
        System.out.println("Empolyee name is " + name);
        System.out.println("Empolyee id is " + id);
        System.out.println("Empolyee salary is " + salary);
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter company name : ");
        String companyName = sc.nextLine();
        System.out.print("Enter employee name : ");
        String name = sc.nextLine();
        System.out.print("Enter employee id : ");
        int id = sc.nextInt();
        System.out.print("Enter employee salary : ");
        int salary = sc.nextInt();

        Employee em = new Employee();
        em.getData(id, name, salary, companyName);
        em.putData();
        sc.close();
    }
}