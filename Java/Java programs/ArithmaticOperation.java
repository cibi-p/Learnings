import java.util.Scanner;

class Arithmatic
{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter 2 numbers");
        int a=scan.nextInt();
        int b=scan.nextInt();
        System.out.println("Addition of the number is "+(a+b));
        System.out.println("subration of the number is "+(a-b));
        System.out.println("multiplication of the number is "+(a*b));
        System.out.println("Division of the number is "+(a/b));
    }
}