
import java.util.Scanner;

public class Main {
    public static int tile[][];
    public static int DP_minimum[][];
    public static int DP_maximum[][];
    public static int maxi(int a,int b){
        if(a>b)
            return a;
        else
            return b;
    }
    public static int maxi(int a,int b,int c){
        if(a>=b&&a>=c)
            return a;
        else if(b>=a&&b>=c)
            return b;
        else if(c>=a&&c>=b)
            return c;
        else
            return 0;
    }
    public static int mini(int a,int b,int c){
        if(a<=b&&a<=c)
            return a;
        else if(b<=a&&b<=c)
            return b;
        else if(c<=a&&c<=b)
            return c;
        else
            return 0;
    }
    public static int mini(int a,int b){
        if(a>b)
            return b;
        else
            return a;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        tile=new int[N][3];
        DP_maximum=new int[N][3];
        DP_minimum=new int[N][3];
        int max=0;
        int min=100000000;
        for(int i=0;i<N;i++){
            for(int i1=0;i1<3;i1++) {
                tile[i][i1] = sc.nextInt();
                DP_maximum[i][i1]=tile[i][i1];
                DP_minimum[i][i1]=tile[i][i1];
            }
        }
        for(int i=1;i<N;i++){
            for(int k=0;k<3;k++){
                if(k==0){
                    DP_maximum[i][k]+=maxi(DP_maximum[i-1][0],DP_maximum[i-1][1]);
                    DP_minimum[i][k]+=mini(DP_minimum[i-1][0],DP_minimum[i-1][1]);
                }
                else if(k==1){
                    DP_maximum[i][k]+=maxi(DP_maximum[i-1][0],DP_maximum[i-1][1],DP_maximum[i-1][2]);
                    DP_minimum[i][k]+=mini(DP_minimum[i-1][0],DP_minimum[i-1][1],DP_minimum[i-1][2]);
                }
                else if(k==2){
                    DP_maximum[i][k]+=maxi(DP_maximum[i-1][1],DP_maximum[i-1][2]);
                    DP_minimum[i][k]+=mini(DP_minimum[i-1][1],DP_minimum[i-1][2]);
                }
            }
            if(i==N-1) {
                max = maxi(DP_maximum[i][0], DP_maximum[i][1], DP_maximum[i][2]);
                min= mini(DP_minimum[i][0],DP_minimum[i][1],DP_minimum[i][2]);
            }
        }
        System.out.println(max+" "+min);
    }

}