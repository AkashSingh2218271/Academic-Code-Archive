import java.util.*;
import java.sql.*;

public class UpdateDel {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Connection connection = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "");
            Statement statement = connection.createStatement();

            System.out.println("Select option:\n1. Update\n2. Delete");
            System.out.print("Enter option: ");
            int option = sc.nextInt();

            if (option != 1 && option != 2) {
                System.out.println("Wrong option selected!!");
                return;
            }

            System.out.println("Enter name of person");
            String name = sc.next();
            String query;
            if (option == 1) {
                System.out.println("Enter new Age");
                int newAge = sc.nextInt();
                System.out.println("Enter new Name");
                String newName = sc.next();

                query = "UPDATE `Details of student` SET `Name`='" + newName + "',`Age`='" + newAge + "' WHERE `Name`='" + name
                        + "';";
                statement.execute(query);

                System.out.println("Data has been successfully updated!!");
            } else if (option == 2) {

                query = "DELETE FROM `Details of student` WHERE `name`='" + name + "';";
                statement.execute(query);

                System.out.println("Data has been deleted successfully!!");
            }

        } catch (Exception e) {
            System.out.println(e);
        } finally {
            sc.close();
        }
    }
}