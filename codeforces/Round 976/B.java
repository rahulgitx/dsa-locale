import java.util.*;

public class B{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while(t > 0){
            t--;
            long k = scanner.nextLong();

            long n = 1, sum = 0;

            boolean flag = false;
            long p = 1l;
            while(sum < k){
                if(flag){
                    n = n+1l;
                    flag = false;
                }
                else{
                    n = n + (p*2l);
                    sum = sum + (p*2l);
                    p = p*2l;  
                    flag = true;
                }
                // System.out.println(n + " " + sum  + " " + p);
            }        
            if(sum > k){
                n = n-(sum-k);
            }    
            else{
                n += k-sum;
            }
            System.out.println(n);
        }
    }
}