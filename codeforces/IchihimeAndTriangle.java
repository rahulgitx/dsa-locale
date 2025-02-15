import java.util.*;

public class IchihimeAndTriangle{
    public static Scanner scanner = new Scanner(System.in);

    public static void solve(){
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        System.out.println(b + " " + c + " " + c);
    }
    public static void main(String...args){
        int t = scanner.nextInt();

        while(t > 0){
            t--;
            solve();
        }
    }
}