import java.util.*;

public class Main {

    static int[][] forest=new int[501][501];
    static int[][] DP=new int[501][501];
    static int[] MX={-1,1,0,0};
    static int[] MY={0,0,-1,1};
    static int n;
    public static int DFS(int a,int b){

        for(int i=0;i<4;i++){
                int xm=b+MX[i];
                int ym=a+MY[i];
                //움직일 수 있는 경우
                if(0<=xm&&xm<n&&0<=ym&&ym<n&&forest[ym][xm]>forest[a][b]){
                    DP[a][b]=Math.max(DP[a][b],DFS(ym,xm)+1);
                }
        }
        return DP[a][b];
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                forest[i][k]=sc.nextInt();
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                DFS(i,k);
                if(ans<DP[i][k]){
                    ans=DP[i][k];
                }
            }
        }

        System.out.println(ans+1);

    }
}
