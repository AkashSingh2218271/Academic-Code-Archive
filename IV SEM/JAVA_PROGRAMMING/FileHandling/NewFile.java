package FileHandling;

import java.io.FileWriter; 
import java.io.File;
import java.io.IOException;

public class NewFile {
    public static void main(String[] args) {
        try{
            File obj= new File("text.txt");
            if(obj.createNewFile()){
                System.out.println("NewFile Created:"+obj.getName());
            }
            else{
                System.out.println("NewFile already exists");
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
        try {
            FileWriter Writer= new FileWriter("text.txt");
            Writer.write("Hello");
            Writer.close();
            System.out.println("Successfully written.");
        }
        catch (IOException e) {
            System.out.println("An error has occurred.");
            e.printStackTrace();
        }
    }
}

