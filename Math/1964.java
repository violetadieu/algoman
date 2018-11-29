import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
       Scanner sc =new Scanner(System.in);
       long  N=sc.nextInt();
       long total= (((3 * N * N) + (5 * N) + 2) / 2);


       System.out.println(total%45678);
    }

}
