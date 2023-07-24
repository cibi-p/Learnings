import java.util.Scanner;

class demo{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter 1:");
        int a=scan.nextInt();
        if(a==1)
            System.out.println("You Pressed 1");
        else
            System.out.println("You are not pressed 1");
    }
}