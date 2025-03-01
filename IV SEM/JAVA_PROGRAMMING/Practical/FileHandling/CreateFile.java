import java.io.FileWriter;
import java.io.IOException;

public class CreateFile {
    public static void main(String[] args) {
        try {
            FileWriter writer = new FileWriter("NewFile.txt");
            
            writer.write("Hello, I have created a new file");
            
            writer.close();
            
            System.out.println("File has been created successfully!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

