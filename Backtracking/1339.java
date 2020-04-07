import java.util.*;

public class Main {
    static int[] Alpha=new int[26];
    static boolean[] Al=new boolean[26];
    static String[] str=new String[10];
    static int cnt=0;
    static int N=0;
    static int ans=0;

    public static int word_sum(int N,int[] permu){
        int sum=0;
        for(int i=0;i<N;i++){
            String tmp="";
            for(int k=0;k<str[i].length();k++){
                tmp+=Integer.toString(Alpha[str[i].charAt(k)-65]);
            }
            sum+=Integer.parseInt(tmp);
        }
        return sum;
    }

    public static void permutation(int[] num, int depth, int total){
        if(depth==cnt){
            int tmp=word_sum(N,num);
            if(tmp>ans)
                ans=tmp;
        }

        for(int i=depth;i<total;i++){
            swap(num,depth,i);
            permutation(num,depth+1,total);
            swap(num,depth,i);
        }

    }

    static void swap(int[] num, int i, int j) {

        int temp = num[i];

        num[i] = num[j];
        num[j] = temp;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        N=sc.nextInt();
        for(int i=0;i<N;i++){
            str[i]=sc.next();
            for(int k=0;k<str[i].length();k++){
                if(!Al[str[i].charAt(k)-65]) {
                    Al[str[i].charAt(k) - 65] = true;
                    cnt++;
                }
            }
        }
        int tmp=9;
        for(int i=0;i<26;i++){
            if(Al[i]) {
                Alpha[i] = tmp;
                tmp--;
            }
        }
        ans=word_sum(N,Alpha);
        permutation(Alpha,0, cnt);

        System.out.print(ans);
    }
}
