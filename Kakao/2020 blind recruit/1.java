import java.util.*;

public class Algorithm {

     public static int solution(String s) {
        int answer = s.length();
        int max_split=answer/2;

        for(int i=1;i<=max_split;i++){
            String now="";
            int start_index=0;
            int end_index=i;
            List<String>list=new ArrayList<String>();
            //i개씩 글자 자르기
            while(true){
                if(start_index>=s.length())
                    break;
                if(end_index>s.length())
                    end_index=s.length();
                String tmp=s.substring(start_index,end_index);
                list.add(tmp);
                start_index+=i;
                end_index+=i;
            }
            //연속 체크
            String chk=list.get(0);
            for(int k=1;k<list.size();k++) {
                if(list.get(k).equals(chk)){
                    list.set(k,"");
                }
                else
                    chk=list.get(k);
            }

            for(int p=0;p<list.size();p++){
                int num=1;
                if(list.get(p).equals(""))
                    continue;

                for(int m=p+1;m<list.size();m++){
                    if(list.get(m).equals(""))
                        num++;
                    else
                        break;
                }
                if(num==1)
                    now+=list.get(p);
                else
                    now+=num+list.get(p);
            }
            if(now.length()<answer)
                answer=now.length();

        }

        return answer;
    }

    public static void main(String[] args){

        String s="ababcdcdababcdcd";
        int ans=solution(s);
        System.out.println(ans);
    }
}
