import java.util.*;

public class B{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t > 0){
            t--;

            int n = scanner.nextInt();
            int[] arr = new int[n];

            for(int i=0; i<n; i++){
                arr[i] = scanner.nextInt();
            }
            Arrays.sort(arr);

            System.out.println(arr[n/2]);
        }
    }
}