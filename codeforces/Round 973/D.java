import java.util.*;

public class D{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0){
            t--;
            
            int n = scanner.nextInt();
            int x = scanner.nextInt();
            int y = scanner.nextInt();

            int res = 0;
            while(n > 0){
                n = n-Math.min(x, y);
                res++;
            }
            System.out.println(res);
        }
    }
}