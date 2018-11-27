
import java.util.Arrays;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int dp[][]=new int[201][201];
        int n=sc.nextInt();
        int k=sc.nextInt();
        for(int i=0;i<=n;i++)
        { dp[1][i] = 1; }
        for(int i=1;i<=k;i++)
        { for(int j=0;j<=n;j++)
        { for(int l=0;l<=j;l++)
        { dp[i][j] += dp[i-1][j-l];
        }
        }
        }

        System.out.println(dp[k][n]);
    }
}
