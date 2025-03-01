import java.util.Scanner;

public class Interest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter principal amount : ");
        float P = sc.nextFloat();
        System.out.print("Enter time in years : ");
        int t = sc.nextInt();
        // Creating objects of HDFC, SBI, and PNB
        HDFC hdfc = new HDFC();
        SBI sbi = new SBI();
        PNB pnb = new PNB();

        // Displaying the interest rates
        System.out.println("HDFC Interest : " + hdfc.getRateOfInterest(P, t) + " Total amount : " + (P + hdfc.getRateOfInterest(P, t)));
        System.out.println("SBI Interest : " + sbi.getRateOfInterest(P, t) + " Total amount : " + (P + sbi.getRateOfInterest(P, t)));
        System.out.println("PNB Interest : " + pnb.getRateOfInterest(P, t) + " Total amount : " + (P + pnb.getRateOfInterest(P, t)));
        sc.close();
    }
}

/**
 * Bank
 */
class Bank{
    public double getRateOfInterest(float P, int t) {
        return  0.0;
    }
}

/**
 * HDFC extends Bank
 */
class HDFC extends Bank {
    public double getRateOfInterest(float P, int t) {
        return (P * 4.0 * t)/100;
    }
}

class SBI extends Bank {
    public double getRateOfInterest(float P, int t) {
        return( P * 4.5 * t)/100;
    }
}

class PNB extends Bank {
    public double getRateOfInterest(float P, int t) {
        return (P * 5.0 * t)/100;
    }
}