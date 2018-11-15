import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        long DP[][]=new long[n][n];
        long cell[][]=new long[n][n];
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                cell[i][k]=sc.nextInt();
            }
        }
        DP[0][0]=1;
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(i==n-1&&k==n-1)
                    break;
                if(DP[i][k]!=0){
                    if(i+cell[i][k]<n)
                        DP[(int) (i+cell[i][k])][k]++;
                    if(k+cell[i][k]<n)
                        DP[i][(int) (k+cell[i][k])]++;
                }
            }
        }
        System.out.println(DP[n-1][n-1]);
    }
}
