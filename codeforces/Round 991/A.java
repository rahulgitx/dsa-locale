import java.util.*;

public class A{
    public static void main(String...args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t>0){
            t--;
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] v = new int[n];

            for(int i=0; i<n; i++){
                String s = sc.next();
                v[i] = s.length();
            }

            int res = 0;
            int ind = 0;
            for(int i=0; i<n; i++){
                if(res+v[i] > m) break;
                res += v[i];
                ind++;
            }
            System.out.println(ind);
        }
    }
}