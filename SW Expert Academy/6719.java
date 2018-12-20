import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static int course[];
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int Test=sc.nextInt();
        for(int i0=1;i0<=Test;i0++){
            double result=0.0;
            int N=sc.nextInt();
            int K=sc.nextInt();
            course=new int[N+1];
            for(int i=1;i<=N;i++){
                course[i]=sc.nextInt();
            }
            Arrays.sort(course);
            for(int i=N-K;i<N;i++){
                result+=course[i];
                result/=2;
            }
            System.out.println("#"+i0+" "+result);
        }
    }

}