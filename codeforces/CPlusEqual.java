import java.util.*;

public class CPlusEqual{
    public static void func(int a, int b, int n){
        int res = 0;
        while(a <= n && b <= n){
            if(a < b){
                a += b;
            }
            else{
                b += a;
            }
            res++;
        }
        System.out.println(res);
    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        while(t>0){
            t--;

            int a = scanner.nextInt(), b = scanner.nextInt(), n = scanner.nextInt();
            func(a, b, n);
        }
    }
}