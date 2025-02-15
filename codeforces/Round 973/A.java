import java.util.*;

public class A{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0){
            t--;
            
            int n = scanner.nextInt();
            int x = scanner.nextInt();
            int y = scanner.nextInt();

            int res = 0;
            if(n%(Math.min(x,y)) > 0) res++;
            res += n/(Math.min(x,y));
            
            System.out.println(res);
        }
    }
}