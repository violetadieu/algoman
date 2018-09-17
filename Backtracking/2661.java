import java.util.Scanner;

public class Main {
    static int N;
    static boolean stop=false;
    public static boolean satisfy(String s){
        int len=s.length();
        int loop=len/2;
        int start=len-1;
        int end=len;

        for(int i=1;i<=loop;i++){
            if(s.substring(start-i,end-i).equals(s.substring(start,end))){
                return false;
            }
            start-=1;
        }
        return true;
    }
    public static void dfs(int i,String s){
        if(stop)
            return ;
        if(i==N){
            stop=true;
            System.out.print(s);
        }
        for(int p=1;p<=3;p++){
            if(satisfy(s+p)){
                dfs(i+1,s+p);
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        N=sc.nextInt();
        dfs(1,"1");
    }

}
