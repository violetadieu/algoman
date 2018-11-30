import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
       Scanner sc =new Scanner(System.in);
       int Test=sc.nextInt();
       boolean DP[][]=new boolean[101][101];

       while(true){
           int result=0;
           if(Test==0)
               break;
           int round=sc.nextInt();
           for(int i=0;i<=round;i++){
               for(int k=0;k<=round;k++)
                   DP[i][k]=true;
           }
           for(int i=2;i<=round;i++){
               for(int k=1;k<=round;k++){
                   DP[i][k]=DP[i-1][k];
                   if(k%i==0){
                       if(DP[i][k]==true)
                           DP[i][k]=false;
                       else
                           DP[i][k]=true;
                   }

               }
           }

               for(int k=1;k<=round;k++)
                   if(DP[round][k]==true)
                       result++;
           System.out.println(result);
           Test--;
       }//while end


    }

}
