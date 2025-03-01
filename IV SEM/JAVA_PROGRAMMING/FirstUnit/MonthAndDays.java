package FirstUnit;

//package JAVA_PROGRAMMING.FirstUnit;

import java.util.Scanner;

public class MonthAndDays {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the month number you want to check between (1 to 12) : ");
        int month = sc.nextInt();
        CalMonthAndDay md = new CalMonthAndDay();
        md.getMonth(month);
        md.calDaysAndMonth();
        sc.close();
    }
}

class CalMonthAndDay {
    int month;
    int sum;
    int days[] = { // Placeholder for index 0 (January)
            31, // January
            29, // February (leap year)
            31, // March
            30, // April
            31, // May
            30, // June
            31, // July
            31, // August
            30, // September
            31, // October
            30, // November
            31 // December
    };

    void getMonth(int month) {
        this.month = month;
        this.sum = 0;
    }

    void calDaysAndMonth() {
        switch (month) {
            case 1:
                System.out.println("Month is january");
                System.out.println(days[month - 1] + " days in january");
                calDays();
                break;
            case 2:
                System.out.println("Month is February");
                System.out.println(days[month - 1] + " days in February ");
                calDays();
                break;
            case 3:
                System.out.println("Month is March: 31");
                System.out.println(days[month] + "days in March: 31");
                calDays();
                break;
            case 4:
                System.out.println("Month is April: 30 ");
                System.out.println(days[month - 1] + " days in April: 30 ");
                calDays();
                break;
            case 5:
                System.out.println("Month is May: 31");
                System.out.println(days[month - 1] + " days in May: 31");
                calDays();
                break;
            case 6:
                System.out.println("Month is June: 30");
                System.out.println(days[month - 1] + " days in june");
                calDays();
                break;
            case 7:
                System.out.println("Month is July: 31 ");
                System.out.println(days[month - 1] + " days in july");
                calDays();
                break;
            case 8:
                System.out.println("Month is August: 31");
                System.out.println(days[month - 1]+ " days in August");
                calDays();
                break;
            case 9:
                System.out.println("Month is September: 30");
                System.out.println(days[month - 1] + " days in September");
                calDays();
                break;
            case 10:
                System.out.println("Month is October: 31");
                System.out.println(days[month - 1] + " days in October");
                calDays();
                break;
            case 11:
                System.out.println("Month is November: 30");
                System.out.println(days[month - 1]+ " days in November");
                calDays();
                break;
            case 12:
                System.out.println("Month is December: 31");
                System.out.println(days[month - 1] + " days in December");
                calDays();
                break;
            default:
                System.out.println("Inavalid Day.");
                break;
        }
    }

    void calDays() {
        for (int i = 0; i < month; i++) {
            sum += days[i];
        }
        System.out.println("Total no. of day are " + sum);
    }
}
