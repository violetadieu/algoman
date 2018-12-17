import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    public static int mount[];
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int Test=sc.nextInt();
        for(int i0=1;i0<=Test;i0++){
            int cnt=sc.nextInt();
            int result=0;
            mount=new int[cnt];
            for(int i=0;i<cnt;i++){
                mount[i]=sc.nextInt();
            }
            for(int i=1;i<cnt;i++){
                int left=0;
                int right=0;
                for(int tmp=i;tmp>0;tmp--){
                    if(mount[tmp]>mount[tmp-1])
                        left++;
                    else
                        break;
                }
                for(int tmp=i;tmp<cnt-1;tmp++){
                    if(mount[tmp]>mount[tmp+1])
                        right++;
                    else
                        break;
                }
                result+=left*right;
            }
            System.out.println("#"+i0+" "+result);
        }
    }

}