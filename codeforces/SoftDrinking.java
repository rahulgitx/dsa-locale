import java.util.*;

public class SoftDrinking{
    public static void main(String... args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int l = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt(); 
        int p = scanner.nextInt();
        int nl = scanner.nextInt();
        int np = scanner.nextInt();

        int minDrinks = (l*k)/nl;
        int minSlice = c*d;
        int minSalt = p/np;
        int res = Math.min(minDrinks, Math.min(minSlice, minSalt))/n;
        System.out.println(res);
    }
}