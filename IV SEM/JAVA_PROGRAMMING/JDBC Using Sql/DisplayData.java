import java.util.*;
import java.sql.*;

public class DisplayData {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Connection connection = null;

        try {
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "");

            Statement statement;
            ResultSet result;

            statement = connection.createStatement();

            System.out.println("Enter name of table to display");
            String tname = sc.nextLine();

            String query = "SELECT * FROM `" + tname + "`;";
            result = statement.executeQuery(query);

            System.out.println();
            System.out.println("Name\t\tAge");

            while (result.next()) {
                int age = result.getInt("Age");
                String name = result.getString("Name");

                System.out.println(name + "\t\t" + age);
            }

        } catch (Exception e) {
            System.out.println(e);
        } finally {
            sc.close();
        }
    }
}