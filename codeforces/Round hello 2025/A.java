import java.util.*;

public class A{
    public static void main(String...args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t>0){
            t--;
            int n = sc.nextInt();
            int m = sc.nextInt();
            int ans = Math.max(n,m) + 1;
            System.out.println(ans);
        }
    }
}