import java.util.*;

public class ChewbacccaAndNumber{
    public static void helper(long n){
        // if(n == 9 || n == 0){
        //     System.out.println(9);
        //     return;
        // }
        long res = 0;
        long m = 1;
        do{
            long newDig = Math.min(9-(n%10), n%10);
            if(newDig == 0 && n < 10){
                newDig = 9;
            }
            res += newDig * m;
            m = m*10; 
            n = n/10;
        }while(n>0);

        System.out.println(res);
    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        long n = scanner.nextLong();

        helper(n);
    } 
}