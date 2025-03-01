import java.util.*;
import java.sql.*;

public class InsertData {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Connection connection = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "");
            Statement statement;
            statement = connection.createStatement();

            System.out.println("Enter size of details");
            int n = sc.nextInt();

            while (n > 0) {
                System.out.println("Enter age");
                int age = sc.nextInt();
                System.out.println("Enter name");
                String name = sc.next();

                String query = "INSERT INTO `Details of student` (`Name`,`Age`) VALUES ('" + name + "', '" + age + "')";
                statement.execute(query);
                n--;

                System.out.println("next...");
            }

            System.out.println("All data has been inserted in table (inform) successfully!!");

        } catch (Exception e) {
            System.out.println(e);
        } finally {
            sc.close();
        }
    }
}



