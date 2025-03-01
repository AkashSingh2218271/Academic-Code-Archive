package FirstUnit;

//package JAVA_PROGRAMMING.FirstUnit;

import java.util.Scanner;
public class LeapYear {

    public static boolean leapYearOrNot(int y) {
        if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) {
            return true;
        }
        return false;
    }

    public static boolean leapYearOrNotApproch2(int y) {
        if (y % 400 == 0) {
            return true;    
        } else if (y % 100 == 0) {
            return false;   
        } else if (y % 4 == 0) {
            return true;    
        } 
        return false;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Entet a year to check leap or not :");
        int year = sc.nextInt();
        boolean boolVal1 = leapYearOrNot(year);
        boolean boolVal2 = leapYearOrNotApproch2(year);
        if (boolVal1 == true && boolVal2 == true) {
            System.out.println(year + " is leap year");
        } else {
            System.out.println(year + " is not a leap year");
        }
        sc.close();
    }
}
