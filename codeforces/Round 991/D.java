import java.util.*;

public class D{
    public static void main(String...args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        // String newline = sc.nextLine();
        while(t>0){
            t--;
            String s = sc.next();
            int n = s.length();
            StringBuilder str = new StringBuilder(s);

            for(int i=0; i<s.length(); i++){
                for(int j=i; j>=1 && j>(i-9); j--){
                    if((str.charAt(j)-str.charAt(j-1))>=2){
                        char temp = (char)(str.charAt(j)-1);
                        str.setCharAt(j, str.charAt(j-1));
                        str.setCharAt(j-1, temp);
                    }
                }
            }
            System.out.println(str);
        }
    }
}