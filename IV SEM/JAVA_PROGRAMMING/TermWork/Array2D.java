import java.util.Scanner;

public class Array2D {
    public void insertArr(int a[][]) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < a.length; i++) {
            System.out.println("Enter element in row " + (i + 1));
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] = sc.nextInt();
            }
        }
    }
    public void traverseArr(int a[][]) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
    }
    public boolean serachArr(int a[][], int key) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                if(a[i][j] == key) {
                    return true;
                }
            }
        }
        return false;   
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array : ");
        int n = sc.nextInt();
        System.out.print("Enter a key to serach : ");
        int key = sc.nextInt();
        int a[][] = new int[n][n];
        Array2D arr = new Array2D();
        arr.insertArr(a);
        System.out.println("Array is ");
        arr.traverseArr(a);
        boolean b = arr.serachArr(a, key);
        if (b) {
            System.out.println(key + " is present");   
        } else {
            System.out.println(key + " is not present");
        }
        sc.close();
    }
}
