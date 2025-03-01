import java.util.Scanner;

public class Student {
    int ID;
    String Name;
    String Branch;
    String city;
    String university;
    
    // constructor chaining
    Student (int ID) {
        this.ID = ID;
    }
    Student (int ID, String Name) {
        this(ID);
        this.Name = Name;
    }
    Student (int ID, String Name, String Branch) {
        this(ID, Name);
        this.Branch = Branch;
    }
    Student (int ID, String Name, String Branch, String city) {
        this(ID, Name, Branch);
        this.city = city;
    }
    Student (int ID, String Name, String Branch, String city, String university) {
        this(ID, Name, Branch, city);
        this.university = university;
    }

    // Method to display student details
    public void display() {
        System.out.println("\nStudent details are ->");
        System.out.println("Student name is " + Name);
        System.out.println("Student Id is " + ID);
        System.out.println("Student branch is " + Branch);
        System.out.println("Student university is " + university);
        System.out.println("Student city is " + city);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter student name : ");
        String Name = sc.nextLine();
        System.out.print("Enter student branch : ");
        String Branch = sc.nextLine();
        System.out.print("Enter student university : ");
        String university = sc.nextLine();
        System.out.print("Enter student city : ");
        String city = sc.nextLine();
        System.out.print("Enter student Id : ");
        int ID = sc.nextInt();
        
        Student s = new Student(ID, Name, Branch, city, university);
        s.display();
        sc.close();
    }
}