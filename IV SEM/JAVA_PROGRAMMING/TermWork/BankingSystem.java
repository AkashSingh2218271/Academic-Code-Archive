import java.util.Scanner;

public class BankingSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Welcome to Banking System");
        System.out.print("Enter how many number of account you want to open : ");
        int n = sc.nextInt();
        BankDetails bank[] = new BankDetails[n];
        for (int i = 0; i < bank.length; i++) {
            System.out.println("Enter bank details of client " + (i + 1));
            bank[i] = new BankDetails();
            bank[i].openAccount();
        }
        int choice;
        do {
            System.out.println("\n Menu ");
            System.out.println("1 Display all account details\n2 Search by Account Number\n3 Deposit into account\n4 Withdraw from account\n0 Exit.");
            choice = sc.nextInt();
            switch (choice) {
                case 0:
                    System.out.println("Exiting the app");
                    break;
                case 1:
                    for (int i = 0; i < bank.length; i++) {
                        System.out.println("\nBank details of client " + (i + 1));
                        bank[i].showAccInfo();
                    }
                    break;
                case 2:
                    System.out.print("Enter your account number to show details: ");
                    String aNum = sc.next();
                    boolean flag = false;
                    for (int i = 0; i < bank.length; i++) {
                        flag = bank[i].searchAcc(aNum);
                        if (flag) {
                            break;
                        }
                    }
                    if (!flag) {
                        System.out.println("Search failed ! Account dosen't exist..!!");
                    }
                    break;
                case 3:
                System.out.print("Enter your account number to deposit : ");
                aNum = sc.next();
                flag = false;
                for (int i = 0; i < bank.length; i++) {
                    flag = bank[i].searchAcc(aNum);
                    if (flag) {
                        System.out.print("Enter a amount to deposit in account : ");
                        long amt = sc.nextLong();
                        bank[i].depositInAcc(amt);
                        break;
                    }
                }
                if (!flag) {
                    System.out.println("Search failed ! Account dosen't exist..!!");
                }
                    break;
                case 4:
                System.out.print("Enter your account number to withdraw: ");
                aNum = sc.next();
                flag = false;
                for (int i = 0; i < bank.length; i++) {
                    flag = bank[i].searchAcc(aNum);
                    if (flag) {
                        System.out.print("Enter a amount to withdrawal from account : ");
                        long amt = sc.nextLong();
                        bank[i].withdrawal(amt);
                        break;
                    }
                }
                if (!flag) {
                    System.out.println("Search failed ! Account dosen't exist..!!");
                }
                    break;
                default:
                    System.out.println("Wrong choice");
                    break;
            }
        } while (choice != 0);
        sc.close();
    }
}

/**
 * InnerBankingSystem
 * BankDetails
 */
class BankDetails {
    protected String name;
    private String AccNumber;
    protected String AccType;
    private String password;
    private long balance;
    public long deposit;

    // Constructor to set balance to zero
    BankDetails() {
        this.balance = 0;
    }

    // Method to increament deposit
    public void incDeposit(long dep) {
        this.balance += dep;
    }

    // Method to open Account
    public void openAccount() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your name : ");
        this.name = sc.nextLine();
        System.out.print("Enter your new account password : ");
        this.password = sc.nextLine();
        System.out.print("Enter your new Account number : ");
        this.AccNumber = sc.next();
        System.out.print("Enter your account type : ");
        this.AccType = sc.next();
        System.out.print("Enter the first amount you want deposit : ");
        this.deposit = sc.nextLong();
        this.incDeposit(deposit);
        System.out.println("Account created successfully");
    }

    // Method to show Account details
    public void showAccInfo() {
        System.out.println("Account information -> ");
        System.out.println("Account holder name : " + this.name);
        System.out.println("Account number is " + this.AccNumber);
        System.out.println("Account type is " + this.AccType);
        System.out.println("Balance in account is " + this.balance);
    }

    // Method to deposit money
    public void depositInAcc(long amt) {
        this.incDeposit(amt);
        System.out.println("Deposit Successful");
    }

    // Method to withdrawal money
    public void withdrawal(long amt) {
        if (this.balance != 0) {
            if (amt <= this.balance) {
                this.balance -= amt;
                System.out.println("Amount withdrawal is " + amt);
                System.out.println("Balance in account after withdrawal is " + this.balance);
            } else {
                System.out.println("Insufficient balance ");
            }
        }
    }

    public boolean searchAcc(String accNum) {
        if (accNum.equals(this.AccNumber)) {
            Scanner sc = new Scanner(System.in);
            int i = 1;
            while (i <= 3) {
                System.out.print("Enter your password : ");
                String pass = sc.next();
                if (password.equals(pass)) {
                    showAccInfo();
                    break;
                } else {
                    System.out.println("Wrong password try again !");
                    System.out.println("Attempt remaining " + (3 - i));
                }
                i++;
            }
            return true;
        }
        return false;
    }
}
