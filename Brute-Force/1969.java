//더러운 코드, 사용할거면 반드시 고칠 것

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n,m;
        String answer="";
        int cnt=0;
        n=sc.nextInt();
        m=sc.nextInt();
        String [] DNA= new String[1001];
        for(int i=0;i<n;i++){
            DNA[i]=sc.next();
        }

        for(int i=0;i<m;i++){
            int[] tmp=new int[4];
            for(int k=0;k<n;k++){
                char now=DNA[k].charAt(i);
                if(now=='A')
                    tmp[0]++;
                else if(now=='C')
                    tmp[1]++;
                else if(now=='G')
                    tmp[2]++;
                else if(now=='T')
                    tmp[3]++;
            }
            int max=0;
            int c=0;
            for(int k=0;k<4;k++){
                if(tmp[k]>c) {
                    c = tmp[k];
                    max=k;
                }
            }
            char plus='a';
            int p=0;
            if(max==0){
                plus='A';
                p=n-c;
            }
            else if(max==1){
                plus='C';
                p=n-c;
            }
            else if(max==2){
                plus='G';
                p=n-c;
            }
            else if(max==3){
                plus='T';
                p=n-c;
            }
            answer+=plus;
            cnt+=p;
        }

        System.out.print(answer+"\n"+cnt);
    }
}
