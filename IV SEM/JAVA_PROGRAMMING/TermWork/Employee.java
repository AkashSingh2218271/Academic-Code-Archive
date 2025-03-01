import java.util.Scanner;

class Employee {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter employee name : ");
        String name = sc.nextLine();
        System.out.print("Enter employee department : ");
        String department = sc.nextLine();
        System.out.print("Enter employeee id : ");
        int id = sc.nextInt();
        System.out.print("Enter employee salary : ");
        double salary = sc.nextDouble();
        EmployeeInfo emp = new EmployeeInfo(id, name, department, salary);
        emp.display();
        sc.close();
    }
}
class EmployeeInfo{
    int id;
    String name;
    String department;
    double salary;

    // constructor chaining
    EmployeeInfo(int id) {
        this.id = id;
    }
    EmployeeInfo(int id, String name) {
        this(id);
        this.name = name;
    }
    EmployeeInfo(int id, String name, String department) {
        this(id, name);
        this.department = department;
    }
    EmployeeInfo(int id, String name, String department, double salary)  {
        this(id, name, department);
        this.salary = salary;
    }

    // Method to show employee info
    public void display() {
        System.out.println("\nEmployee details");
        System.out.println("Employee name is " + this.name);
        System.out.println("Employee department is " + this.department);
        System.out.println("Employee id is " + this.id);
        System.out.println("Employee Salary is " + this.salary);
       
    }
}