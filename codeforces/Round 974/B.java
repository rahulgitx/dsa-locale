import java.util.*;

public class B{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t > 0){
            t--;

            int n = scanner.nextInt();
            int k = scanner.nextInt();
            int prevGap = Math.min(k, n);

            int noOfOdds = 0;
            int left = prevGap%10;
            noOfOdds += (prevGap-left)/2;


            int start = n%2==0 ? 0 : 1;
            for(int i=0; i<left; i++){
                if(start%2==1) noOfOdds++;
                start++;
            }

            if(noOfOdds%2==0) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}