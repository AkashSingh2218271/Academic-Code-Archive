import java.sql.*;
import java.util.*;

public class CreateNewTable {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Connection connection = null;
    System.out.println("Enter Table name");
    String name = sc.nextLine();

    try {
      Class.forName("com.mysql.cj.jdbc.Driver");
      connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "");

      Statement statement;
      statement = connection.createStatement();

      String query = "CREATE TABLE `mydb`.`" + name
          + "` (`Name` VARCHAR(20) NOT NULL , `Age` INT NOT NULL) ENGINE = InnoDB;";

      statement.execute(query);

      System.out.println("Table of name (" + name + ") has been created successfully in database (mydb)");

      statement.close();
      connection.close();
    } catch (Exception e) {
      System.out.println(e);
    } finally {
      sc.close();
    }
  }
}
