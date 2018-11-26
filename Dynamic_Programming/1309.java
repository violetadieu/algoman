
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int DP[]=new int[100000];
        int num=sc.nextInt();
        DP[0]=0%9901;
        DP[1]=3%9901;
        DP[2]=7%9901;

        for(int i=3;i<=num;i++){
            DP[i]=(2*DP[i-1])+DP[i-2]%9901;
        }
        System.out.println(DP[num]);
    }
}
