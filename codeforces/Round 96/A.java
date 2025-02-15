import java.util.*;

public class A{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while(t > 0){
            t--;
            int n = scanner.nextInt();
            String s = scanner.next();

            if(s.charAt(0) != s.charAt(n-1)){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
    }
}