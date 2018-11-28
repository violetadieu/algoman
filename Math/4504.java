import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
       Scanner sc =new Scanner(System.in);
       int n=sc.nextInt();
       while(true){
           int tmp=sc.nextInt();
           if(tmp==0)
               break;
           if(n>tmp||tmp%n!=0)
               System.out.println(tmp+" is NOT a multiple of "+n+'.');
           if(tmp%n==0)
               System.out.println(tmp+" is a multiple of "+n+'.');

       }
    }

}
