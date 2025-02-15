import java.util.*;

public class A{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while(t > 0){
            t--;

            int n = scanner.nextInt();
            int[] arr  = new int[n];
            for(int i=0; i<n; i++){
                int temp = scanner.nextInt();
                arr[i] = temp;
            }
            if(n>2){
                System.out.println("NO");
            }
            else{
                if(arr[1]-arr[0] <= 1){
                    System.out.println("NO");
                }
                else{
                    System.out.println("YES");
                }
            }
        }
    }
}