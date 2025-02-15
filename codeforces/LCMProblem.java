import java.util.*;

public class LCMProblem{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while(t>0){
            t--;
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if(2*x > y){
                System.out.println(-1 + " " + -1);
                continue;
            }
            System.out.println(x + " " + 2*x);
        }
    }
}