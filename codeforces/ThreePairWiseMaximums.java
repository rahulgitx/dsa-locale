import java.util.*;

public class ThreePairWiseMaximums{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0){
            t--;

            int[] arr = new int[3];
            arr[0] = scanner.nextInt();
            arr[1] = scanner.nextInt();
            arr[2] = scanner.nextInt();
            Arrays.sort(arr);

            if(arr[0] == arr[1] && arr[1] == arr[2]){
                System.out.println("YES");
                System.out.println(arr[0] + " " + arr[0] + " " + arr[0]);
            }
            else if(arr[2] == arr[1]){
                System.out.println("YES");
                System.out.println(arr[2] + " " + arr[0] + " " + 1);
            }
            else{
                System.out.println("NO");
            }

        }
    }
}