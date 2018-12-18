import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Solution {
    public static HashSet<Integer> DP;
    public static List<Integer> num;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int Test=sc.nextInt();
        for(int i0=1;i0<=Test;i0++){
            int cnt=sc.nextInt();
            int result=0;
            DP=new HashSet<Integer>();
            DP.add(0);
            for(int i=0;i<cnt;i++){
                int tmp=sc.nextInt();
                int sizeoflist=DP.size();
                num=new ArrayList<Integer>(DP);
                for(int i1=0;i1<sizeoflist;i1++){
                    DP.add(num.get(i1)+tmp);
                }
            }
            result=DP.size();
            System.out.println("#"+i0+" "+result);
        }
    }

}