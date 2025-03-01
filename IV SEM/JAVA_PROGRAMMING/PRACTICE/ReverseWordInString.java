import java.util.Scanner;

public class ReverseWordInString {
   
    public static String reverseWords(String str) {
        if (str == null || str.isEmpty()) {
            return str;
        }
        String s = "";
        String ans = "";
        int j = 0, n = str.length();
        for (int i = 0; i < n; i++) {
            while (i < n && str.charAt(i) != ' ') {
                i++;
            }
            while (j < i) {
                s = str.charAt(j) + s;
                j++;
            }
            ans += s;
            s = "";
            if (i < n && str.charAt(i) == ' ') {
                ans += ' ';
            }
        }
        return ans;
    }
    

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string : ");
        String str = sc.nextLine();
        System.out.println(str + " after in place word reversing " + reverseWords(str));
        sc.close();
    }
}
