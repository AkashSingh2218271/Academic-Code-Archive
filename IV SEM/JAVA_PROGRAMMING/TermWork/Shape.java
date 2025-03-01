import java.util.Scanner;

public class Shape {
    public float area(float l, float b) {
        return l * b;
    }
    public int area(int b, int h) {
        return (b * h)/2;
    }
    public float area(float r) {
        return (r * r * 3.14f);
    }

    public static void main(String[] args) {
        Scanner sc  = new Scanner(System.in);
        System.out.print("Enter length and breath of rectangle respectively : ");
        float l = sc.nextFloat();
        float b = sc.nextFloat();
        System.out.print("Enter base and height of triangle respectively : ");
        int ba = sc.nextInt();
        int h = sc.nextInt();
        System.out.print("Enter radius of a circle : ");
        float r = sc.nextFloat();
        Shape s = new Shape();
        float rArea = s.area(l, b);
        float cArea = s.area(r);
        int tArea = s.area(ba, h);
        System.out.println("Area of rectangle is " + rArea + " sq unit");
        System.out.println("Area of triangle is " + tArea + " sq unit");
        System.out.println("Area of circle is " + cArea + " sq unit");
        sc.close();
    }
}
