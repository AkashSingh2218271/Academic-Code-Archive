import java.util.Scanner;

public class ReverseString {
    public static String reverse(String str) {
        String revStr = "";
        for (int i = 0; i < str.length(); i++) {
            revStr = str.charAt(i) + revStr;
        }
        return revStr;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string : ");
        String str = sc.nextLine();
        System.out.println("Reverse of string " + str + " is " + reverse(str));
        sc.close();
    }
}
