import java.util.*;

public class C{
    public static void solve(int n, long sum, int[] arr){
        Arrays.sort(arr);


        long threshold = arr[n/2];
        long high = Long.MAX_VALUE, low = 0;
        long res = 0;

        while(low <= high){
            long mid = low + (high-low)/2;
            long avg = (sum + mid);
            // System.out.println(mid + " " + avg);
            if(avg > threshold*(2*n)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        System.out.println(res);

    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0){
            t--;

            int n = scanner.nextInt();
            int[] arr = new int[n];
            long sum = 0;
            for(int i=0; i<n; i++){ 
                arr[i] = scanner.nextInt();
                sum += arr[i];
            }
            if(n<=2){
                System.out.println(-1);
            }
            else{
                solve(n, sum, arr);
            }
         }
        
    }
}