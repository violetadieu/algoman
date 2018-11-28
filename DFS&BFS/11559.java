
import java.awt.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static char[][] s=new char[12][6];
    static int[] MX= {-1,1,0,0};
    static int[] MY= {0,0,-1,1};
    static boolean[][] visit=new boolean[12][6];
    static ArrayList<Point> list;
    public static void down(){
        for(int i=0;i<6;i++){
            for(int k=10;k>=0;k--){
                for(int p=11;p>k;p--){
                    if(s[k][i]!='.'&&s[p][i]=='.'){
                        s[p][i]=s[k][i];
                        s[k][i]='.';
                        break;
                    }
                }
            }
        }
    }

    public static void dfs(int x, int y, char target){
        for(int i=0;i<4;i++){
            int nx=MX[i]+x;
            int ny=MY[i]+y;
            if(0<=nx&&nx<=12&&0<=ny&&ny<=12){
                if(!visit[nx][ny]&&s[nx][ny]==target){
                    list.add(new Point(ny,nx));
                    visit[nx][ny]=true;
                    dfs(nx,ny,target);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));
        int total=0;
        for(int i=0;i<12;i++) {
            s[i] = sc.readLine().toCharArray();
        }
            while(true) {
            boolean flag=false;
            visit=new boolean[12][6];
            for (int i = 0; i < 12; i++) {
                for (int k = 0; k < 6; k++) {
                    if (s[i][k] != '.'&&!visit[i][k]) {
                        list=new ArrayList<Point>();
                        dfs(k, i, s[i][k]);
                        if(list.size()>=4){
                            flag=true;
                            for(Point p : list){
                                s[p.y][p.x]='.';
                            }
                        }
                    }
                }
            }
            if(!flag)
                break;
            else
                total++;

            down();
        }
        System.out.println(total);
    }

    public static class Point{
        int y,x;

        Point(int y,int x){
            this.y=y;
            this.x=x;
        }
    }
}
