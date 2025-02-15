import java.util.*;

public class CapsLock{
    public static boolean small(char c){
        if('a' <= c && c <= 'z') return true;
        return false;
    }
    public static boolean capital(char c){
        if('A' <= c && c <= 'Z') return true;
        return false;
    }
    public static void func(String s){
        StringBuilder res = new StringBuilder();
        for(int i=0; i<s.length(); i++){
            if(i==0){
                if(small(s.charAt(i))){
                    res.append((char)(s.charAt(i) - ('a'-'A')));
                }
                else{
                    res.append((char)(s.charAt(i)+('a'-'A')));
                }
            }
            else{
                if(capital(s.charAt(i))){
                    res.append((char)(s.charAt(i) + ('a'-'A')));
                }
                else{
                    System.out.println(s);
                    return;
                }
            } 
        }
        System.out.println(res);
    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        func(s);
    }
}