import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;

public class Main {

    static String[] numstr=new String[10];
    static int maxValue=0;
    static int n;

    public static void main(String[] args) {
        HashMap<Character,Integer>hm=new HashMap<>();
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        try {
            n=Integer.parseInt(br.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
        for(int i=0;i<n;i++){
            try {
                numstr[i]=br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            for (int j = 0; j < numstr[i].length(); j++) {

                char numChar = numstr[i].charAt(j);

                hm.put(numChar, 0);
            }
        }

        int[] num=new int[hm.size()];
        for(int i=0;i<num.length;i++){
            num[i]=9-i;
        }
        permutation(num,num.length,num.length,0,hm);
        System.out.print(maxValue);
    }
    public static void permutation(int[]num,int k,int n,int depth,HashMap<Character,Integer>hm){
        if(depth==k){
            Iterator<Character>it=hm.keySet().iterator();
            while(it.hasNext()){
                hm.replace(it.next(),num[k--]);
            }
            chkmaxvalue(hm);
            return;
        }

        for(int i=depth;i<n;i++){
            swap(num,depth,i);
            permutation(num,k,n,depth+1,hm);
            swap(num,depth,i);
        }

    }
    public static void swap(int[] num, int i, int j) {

        int temp = num[i];

        num[i] = num[j];
        num[j] = temp;
    }
    public static void chkmaxvalue(HashMap<Character,Integer>hm){
        int sum=0;
        for(int i=0;i<n;i++){
            String str=numstr[i];

            int expo=1;

            for(int p=str.length()-1;p>=0;p--){
                char tmp=str.charAt(p);
                sum+=hm.get(tmp)*expo;
                expo*=10;
            }
        }
        if(maxValue<sum)
            maxValue=sum;
    }
}
