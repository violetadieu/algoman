import java.math.BigInteger;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int Test=sc.nextInt();

        for(int i0=1;i0<=Test;i0++){
            int N=sc.nextInt();
            BigInteger result= BigInteger.valueOf(0);
            for(int i=0;i<N;i++){
                int tmp=sc.nextInt();
                int pow=tmp%10;
                BigInteger powed=new BigInteger(String.valueOf(tmp/10));
                result=result.add(powed.pow(pow));
            }
            System.out.println("#"+i0+" "+result);
        }
    }

}