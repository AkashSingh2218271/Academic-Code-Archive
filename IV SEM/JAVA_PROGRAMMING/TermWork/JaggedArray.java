import java.util.Scanner;

public class JaggedArray {
    public void insertArr(int a[][]) {
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < a.length; i++) {
            System.out.println("Enter element in array row " + (i + 1));
            for (int j = 0; j < a[i].length; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        sc.close();
    }

    public void traverseArr(int a[][]) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int a[][] = new int[3][];
        a[0] = new int[3];
        a[1] = new int[4];
        a[2] = new int[2];
        JaggedArray arr = new JaggedArray();
        System.out.println("Enter element in array : ");
        arr.insertArr(a);
        System.out.println("Jagged array is ");
        arr.traverseArr(a);
    }
}
