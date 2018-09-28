import java.util.Scanner;

public class Main {

    static int DP[]=new int[31];

    static int n;

    public static void main(String[] args) {
        int sum=0;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();

        DP[0]=0;
        DP[2]=3;
        DP[4]=11;//DP[2]*DP[2]+2

        //DP[i]=(i:2~i-2)
        for(int k=6;k<=n;k+=2) {
            DP[k]+=3*DP[k-2];
            DP[k] += 2;
            for(int i=k-4;i>=2;i-=2){
                DP[k]+=2*DP[i];
            }
        }
        System.out.print(DP[n]);
    }
}
