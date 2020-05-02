import java.util.*;

public class Algorithm {

    public static boolean chk_lock(int[][] lock,int[][] table,int start){
        for(int i=start;i<start+lock[0].length;i++){
            for(int k=start;k<start+lock[0].length;k++){
                if(table[i][k]!=1)
                    return false;
            }
        }
        return true;
    }

    public static int[][] round(int[][] key){
        int m=key[0].length;
        int [][] result=new int[m][m];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                //왼쪽 90도
                //temp[i][j] = key[j][m - i - 1];
                //오른쪽 90도
                result[i][j] = key[m - j - 1][i];
            }
        }
        return result;
    }

    public static int[][] insert_table(int[][]key,int[][] original,int start_y,int start_x){
        int size=original[0].length;
        int[][] t=new int[size][size];

        for(int i=0;i<size;i++){
            for(int k=0;k<size;k++){
                t[i][k]=original[i][k];
            }
        }

        for(int key_y=0,i=start_y;i<start_y+key[0].length;i++,key_y++){
            for(int key_x=0, k=start_x;k<start_x+key[0].length;k++,key_x++){
                t[i][k]+=key[key_y][key_x];
            }
        }
        return t;
    }

    public static boolean chk(int[][] key,int[][] lock){
         int size=2*(key[0].length-1)+lock[0].length;
         int[][] table=new int[size][size];
         int[][] save=new int[size][size];
         for(int lock_i=0,i=key[0].length-1;i<key[0].length-1+lock[0].length;i++,lock_i++){
             for(int lock_k=0,k=key[0].length-1;k<key[0].length-1+lock[0].length;k++,lock_k++){
                 table[i][k]=lock[lock_i][lock_k];
             }
         }

        for(int i=0;i<=table[0].length-key[0].length;i++){
            for(int p=0;p<=table[0].length-key[0].length;p++){
                int[][] tmp=insert_table(key,table,i,p);
                if(chk_lock(lock,tmp,key[0].length-1))
                    return true;
            }
        }

        return false;
    }

    public static boolean solution(int[][] key, int[][] lock) {
        int [][]now=key;
        for(int i=0;i<4;i++){
            if(chk(now,lock)){
                return true;
            }
            now=round(now);
        }
        return false;
    }

    public static void main(String[] args){
        int[][] key={{0,0,0},{1,0,0},{0,1,1}};
        int[][] lock={{1,1,1},{1,1,0},{1,0,1}};
       boolean ans=solution(key,lock);
        System.out.println(ans);
    }
}
