package FirstUnit;

import java.util.Scanner;

public class PrimeNumber {
    public static boolean primeNumberOrNot(int n) {
        for(int i = 2; i < Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return  true;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number to check prime or not :");
        int n = sc.nextInt();
        boolean bool = primeNumberOrNot(n);
        if (bool) {
            System.out.println(n + " is prime number");
        } else {
            System.out.println(n + " is not a prime number");
        }
        sc.close();
    }
}
