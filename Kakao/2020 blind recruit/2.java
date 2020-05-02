import java.util.*;

public class Algorithm {

    public static boolean iscorrect(String s){
        Stack<Character>stack=new Stack<Character>();
        if(s.charAt(s.length()-1)!=')')
            return false;
        for(int i=0;i<s.length();i++){
            char now=s.charAt(i);
            if(now=='(')
                stack.push(now);
            else if(now==')'){
                if(stack.empty())
                    return false;
                else if(stack.peek()=='(')
                    stack.pop();
            }

        }
        if(stack.empty())
            return true;
        return false;
    }

    public static String[] seperate(String s){
        String[] result=new String[2];
        int balance=0;
        int i=0;
        do {
            if(s.charAt(i)=='(')
                balance++;
            else
                balance--;
            if(balance==0)
                break;
            i++;
        }while(i<s.length());
        result[0]=s.substring(0,i+1);
        result[1]=s.substring(i+1,s.length());
        return result;
    }

    public static String reverse(String s){
        String tmp="";
        for(int i=0;i<s.length();i++){
            char now=s.charAt(i);
            if(now=='(')
                tmp+=')';
            else
                tmp+='(';
        }
        return tmp;
    }

    public static String process(String s){
        String answer = "";
        if(s.equals(""))
            return s;
        //분리 완료
        String[]second_step=seperate(s);
        //u==0,v==1
        //u가 올바르면
        if(iscorrect(second_step[0])){
            answer+=second_step[0];
            answer+=process(second_step[1]);
        }
        //올바르지 않으면
        else{
            String tmp="("+process(second_step[1])+")";
            tmp+=reverse(second_step[0].substring(1,second_step[0].length()-1));
            return tmp;
        }
        return answer;
    }

    public static String solution(String p) {
        String answer = "";
        if(iscorrect(p))
            return p;

       answer=process(p);

        return answer;
    }
    public static void main(String[] args){

        String s="()))((()";
        String ans=solution(s);
        System.out.println(ans);
    }
}
