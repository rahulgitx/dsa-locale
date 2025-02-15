import java.util.*;

public class C{
    // equation: 2x + 6y = 9-remainder/ 9 + (9-remainder) / 18 + (9-remainder)
    public static boolean solveEquation(long x, long y, long remainder){
        long multiple = 9;
        long diff = multiple-remainder;

        while((2*x + 6*y) >= diff){
            for(int i=0; i<=x && i*2 <= diff; i++){
                long left = diff - (i*2);
                if(left%6==0 && left/6 <= y) return true;
            }
            diff += 9l;
        }
        return false;
    }
    public static void main(String...args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for(; t>0; t--){
            String s = sc.next();


            // equation: 2x + 6y = 9-remainder/ 9 + (9-remainder) / 18 + (9-remainder)
            long x=0, y=0, sum = 0;
            for(int i=0; i<s.length(); i++){
                int n = s.charAt(i)-'0';
                sum += (long)(n);
                if(n==2) x++;
                else if(n==3) y++;
            }

            long remainder = (sum%(9L));

            // System.out.println(sum + " " + remainder + " " + x + " " + y);
            
            if(remainder==0 || solveEquation(x,y,remainder)){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
    }
}