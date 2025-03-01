import java.io.*;

public class BufferInFile {
    public static void main(String[] args) {
        try (FileWriter writer = new FileWriter("abc.txt");
             BufferedWriter bufferedWriter = new BufferedWriter(writer)) {

            System.out.println("Enter some text:");
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String input;
            while ((input = reader.readLine()) != null && !input.isEmpty()) {
                bufferedWriter.write(input);
                bufferedWriter.newLine();
            }
        } catch (IOException e) {
                e.printStackTrace();
        }
        
        System.out.println("Reading from the file...");
        try (BufferedReader fileReader = new BufferedReader(new FileReader("abc.txt"))) {
            String fileText;
            while ((fileText = fileReader.readLine()) != null) {
                System.out.println(fileText);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
       
    }
}

