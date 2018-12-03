import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static ArrayList<Integer> al;
    public static void main(String[] args) {
       Scanner sc =new Scanner(System.in);
       while(true){
           int num=sc.nextInt();
           int sum=1;
           if(num==-1)
               break;
           al=new ArrayList<Integer>();
           al.add(1);
           for(int i=2;i<num;i++){
               if(num%i==0) {
                   al.add(i);
                   sum+=i;
               }
           }
           if(sum==num){
               System.out.print(num + " = ");
               for(int i=0;i<al.size();i++){
                   if(i==al.size()-1) {
                       System.out.println(al.get(i));
                       break;
                   }
                   System.out.print(al.get(i)+" + ");
               }
           }
           else
               System.out.println(num + " is NOT perfect.");
       }
    }

}
