import java.util.*;

public class ArrayWithOddSum{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while(t > 0){
            t--;

            int n = scanner.nextInt();
            int[] arr = new int[n];
            boolean odd = false;
            boolean even = false;
            int sum = 0;
            for(int i=0; i<n; i++){
                arr[i] = scanner.nextInt();
                if(arr[i]%2 == 0) even = true;
                else odd = true;
                sum += arr[i];
            }
            if(sum%2 == 1){
                System.out.println("YES");
            }
            else{
                if(odd && even) System.out.println("YES");
                else System.out.println("NO");
            }
        }
    }
}