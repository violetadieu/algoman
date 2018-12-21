import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static int buliding[][];
    public static int visit[];
    public static int N;
    public static int M;
    public static int dijstra(int start){
        int size=65536;
        Queue<Integer> queue=new LinkedList<Integer>();
        queue.add(start);
        visit=new int[N+1];
        for(int i=0;i<=N;i++)
            visit[i]=65536;
        visit[start]=0;
        while(!queue.isEmpty()){
            int top=queue.poll();
            for(int i=1;i<=N;i++){
                if(buliding[top][i]!=0&&visit[top]+buliding[top][i]<visit[i]) {
                    visit[i] = visit[top]+buliding[top][i];
                    queue.add(i);
                }
            }
            if(buliding[top][start]!=0&&visit[top]+buliding[top][start]<size)
                size=visit[top]+buliding[top][start];
            visit[start]=65536;
        }
        return size;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int Test=sc.nextInt();
        for(int i0=1;i0<=Test;i0++){
            int result=65536;
            N=sc.nextInt();//건물개수
            M=sc.nextInt();//도로개수
            buliding=new int[N+1][N+1];
            for(int i=0;i<M;i++){
                int start=sc.nextInt();
                int goal=sc.nextInt();
                int length=sc.nextInt();
                buliding[start][goal]=length;
            }
            for(int i=1;i<=N;i++){
                int tmp=dijstra(i);
                if(tmp<result)
                    result=tmp;
            }
            System.out.println("#"+i0+" "+result);
        }
    }

}