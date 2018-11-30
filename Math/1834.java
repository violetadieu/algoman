import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
       Scanner sc =new Scanner(System.in);
       long  N=sc.nextInt();
       long total=0;
       for(int i=1;i<N;i++){
           total+=N*i+i;
       }


       System.out.println(total);
    }

}
