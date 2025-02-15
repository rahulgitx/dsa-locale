import java.util.*;

public class Bitplusplus{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        scanner.nextLine();
        int res = 0;
        for(int i=0; i<n; i++){
            String s = scanner.nextLine();
            if(s.charAt(1) == '+') res++;
            else res--;
        }
        System.out.println(res);
    }
}