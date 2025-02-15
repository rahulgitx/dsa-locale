import java.util.*;

public class B{
    String sol1(String s){
        int p = 0;
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(c=='L') p--;
            else p++;
        }
        if(p<0) return "L";
        else if(p==0) return "";
        return "R";
    }
    String vowels = "aeiouAEIOU";
    boolean isCons(char c){
        for(int i=0; i<vowels.length(); i++){
            if(c==vowels.charAt(i)) return false;
        }
        return true;
    }

    void replace(StringBuilder str, int ind){
        char baseA = '$';
        char c = str.charAt(ind);
        if('a'<=c && c<='z'){
            baseA = 'a';
        }
        else baseA = 'A';

        int i = c-baseA;
        i++;
        while(!isCons((char)(i+baseA))){ 
            i++;
            if(i>=26) i=0;
        }
        char r = (char)(i+baseA);

        str.setCharAt(ind, r);
    }
    String sol2(String s, int n){
        int pos = 1;
        StringBuilder str = new StringBuilder(s);
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(isCons(c)){
                if(pos%n==0){
                    replace(str,i);
                }
                pos++;
            }
        }
        return str.toString();
    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("hello");
        B b = new B();
        // System.out.println(b.sol2("CodeSignal",3));
        System.out.println(b.sol2("Quiz, Citizenship, puZZle",5));
    }
}