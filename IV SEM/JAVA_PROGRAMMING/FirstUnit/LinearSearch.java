package FirstUnit;

//package JAVA_PROGRAMMING.FirstUnit;

import java.util.Scanner;

public class LinearSearch {

    public static int linearSearch(int arr[], int key) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key) {
                System.out.println(i);
                return i;
            }
        }
        return -1;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter value of n : ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter your key to search");
        int key = sc.nextInt();
        int x = linearSearch(arr, key);
        if (x == -1) {
            System.out.println(key + " is not present");
        } else {
            System.out.println(key + " is present at index " + x);
        }
        
        sc.close();
    }
}

