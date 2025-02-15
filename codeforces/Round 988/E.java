import java.util.*;

public class E{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0){
            t--;

            int n = scanner.nextInt();
            StringBuilder str = new StringBuilder();
            
            System.out.println("? " + 1 + " " + n);
            // System.out.flush();

            int last = scanner.nextInt();
            if(last == 0){
                System.out.println("! IMPOSSIBLE");
                // System.out.flush();
                continue;
            }
            int full = last;

            int loopCount = 1, onesCount = -1;
            int l = 2, r = n;

            while(loopCount < n){
                int inp = 0;
                if(l<r){
                    System.out.println("? " + l + " " + r);
                    // System.out.flush();
                    inp = scanner.nextInt();

                }

                int length = r-l+1;
                
                if(last-inp == 0){
                    str.append('1');
                    onesCount--;
                    while(onesCount == 0 && str.length() < n) str.append('0');
                    if(str.length() == n) break;
                }
                else{
                    str.append('0');
                    onesCount = last-inp;
                }
                l++; loopCount++;
                last = inp;

            }
            if(onesCount > 0) str.append('1');

            System.out.println("! " + str);
            // System.out.flush();
        }
    }
}