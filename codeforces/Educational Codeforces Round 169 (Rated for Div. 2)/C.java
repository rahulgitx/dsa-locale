import java.util.*;

public class C{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while(t>0){
            t--;

            int n = scanner.nextInt(), k = scanner.nextInt();
            int[] arr = new int[n];

            for(int i=0; i<n; i++){
                arr[i] = scanner.nextInt();
            }

            int a = 0, b = 0;
            Arrays.sort(arr);
            for(int i=n-2; i>=0; i=i-2){
                // if(k == 0) break;
                
                if(arr[i+1]-arr[i] >= k){
                    arr[i] = arr[i]+k;
                    k = 0;
                }
                else{
                    k = k - (arr[i+1]-arr[i]);
                    arr[i] = arr[i+1];
                }
                a += arr[i+1];
                b += arr[i];
                // System.out.println(a+":"+b);
                if(i==1) a += arr[0];

            }
            System.out.println(a-b);
        }
    }
}