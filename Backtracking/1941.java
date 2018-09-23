import java.util.Scanner;
import java.util.*;
public class Main {
    static char clas[][]=new char[5][5];
    static int result=0;//경우의 수
    static int select[]=new int[7];

    public static boolean chk(int num){
        if(clas[select[0]/5][select[0]%5]=='S')
            num++;
        for(int i=1;i<7;i++){
            if(select[i-1]+1==select[i]||select[i-1]-1==select[i]||select[i-1]+5==select[i]||select[i-1]-5==select[i]){
                if(clas[select[i]/5][select[i]%5]=='S')
                    num++;
            }
            else
                return false;
        }
        if(num>=4)
            return true;
        return false;
    }

    public static void Perm(int depth){
        if(depth==7){
            if(chk(0)) {
                result++;
                return ;
            }
            return ;
        }
        for(int p=0;p<25;p++){
            select[depth]=p;
            Perm(depth+1);
        }
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        for(int i=0;i<5;i++){
            for(int p=0;p<5;p++){
                clas[i][p]=sc.next().charAt(0);
            }
        }
        Perm(0);

        System.out.print(result);
    }
}
