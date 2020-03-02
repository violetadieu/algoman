import java.util.*;


class Solution {
    
    int getNormalPoint(String page, String word){
        int startIndex = 0;
        page = page.substring(page.indexOf("<body>"),page.indexOf("</body>"));
        word = word.toLowerCase();
        int normalpoint = 0;
        for(;startIndex<page.length();){
            startIndex = page.indexOf(word,startIndex+1);
            if(startIndex==-1)
                break;
            if(!Character.isLetter(page.charAt(startIndex-1))&&!Character.isLetter(page.charAt(startIndex+word.length()))){
                normalpoint++;
                startIndex += word.length();
            }
        }
        return normalpoint;
    }
    
    public int solution(String word, String[] pages) {
        String[] link_name=new String[20];
        double[] link_score=new double[20];
        double[] total_score=new double[20];
        int answer = 0;
        word=word.toLowerCase();
        for(int i=0;i<pages.length;i++){
            //주소 추출
            String head="content=";
            String tail="/>";
            int target_head=pages[i].indexOf(head);
            int target_tail=pages[i].indexOf(tail,target_head+1);
            //현재 페이지
            link_name[i]=pages[i].substring(target_head+head.length(),target_tail);
        }
        
        for(int i=0;i<pages.length;i++){
            ArrayList<String>links=new ArrayList<String>();
        //전부 소문자로 바꾸기
            pages[i]=pages[i].toLowerCase();
        //단어 개수 찾기
            int word_num=getNormalPoint(pages[i],word);
            total_score[i]+=word_num;
            double link_num=0;
            double tmp_score=0.0;
        
            //a 태그
            String head="<a href=\"" ;
            String tail=">";
            int target_head=pages[i].indexOf(head,0);
            int target_tail=pages[i].indexOf(tail,target_head);
            while(true){
                if(target_head==-1||target_tail==-1)
                    break;
                links.add(pages[i].substring(target_head+head.length(),target_tail));
                link_num+=1;
                target_head=pages[i].indexOf(head,target_tail+1);
                target_tail=pages[i].indexOf(tail,target_head+1);
            }
            tmp_score=word_num/link_num;
            for(int k=0;k<20&&link_name[k]!=null;k++){
                for(int p=0;p<links.size();p++){
                    if(link_name[k].equals(links.get(p))){
                        total_score[k]+=tmp_score;
                    }
                }
            }
        }
        double tmp=0;
        for(int i=0;i<20;i++){
            if(tmp<total_score[i]){
                tmp=total_score[i];
                answer=i;
            }
        }
        return answer;
    }
   }
