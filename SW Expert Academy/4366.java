import java.awt.event.MouseAdapter;
import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    public static int len_2;
    public static int len_3;
    public static int change_2(int x){
        int ret=0;
        int by_2=1;
        int iter=(int)Math.log10(x);
        len_2=iter;
        for(int i=0;i<=iter;i++){
            ret+=by_2*(x%10);
            by_2*=2;
            x/=10;
        }
        return ret;
    }
    public static int change_3(int x){
        int ret=0;
        int by_3=1;
        int iter=(int)Math.log10(x);
        len_3=iter;
        for(int i=0;i<=iter;i++){
            ret+=by_3*(x%10);
            by_3*=3;
            x/=10;
        }
        return ret;
    }
    public static int divide(int x){
        for(int i=0;i<=len_2;i++){
            for(int i1=0;i1<=len_3;i1++){
                int pow_2=(int)Math.pow(2,i);
                int pow_3=(int) Math.pow(3,i1);
                if(pow_2+pow_3==x){
                    return (int)Math.pow(2,i);
                }
            }
        }
        return 0;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int Test=sc.nextInt();

        for(int i0=1;i0<=Test;i0++){
            int result=0;
            int num_2=change_2(sc.nextInt());
            int num_3=change_3(sc.nextInt());
            result=num_2+divide((int)Math.abs(num_2-num_3));
            System.out.println("#"+i0+" "+result);
        }
    }

}