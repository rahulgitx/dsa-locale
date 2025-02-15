import java.util.*;

public class B{
    public static void main(String...args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for(; t>0; t--){
            int n = sc.nextInt();
            // int[] arr = new int[n];

            long oddSum=0l, evenSum = 0l;
            long evenLength = 0l, oddLength = 0l;
            for(int i=0; i<n; i++){
                int temp = sc.nextInt();
                if(i%2==0){
                    oddSum += (long)temp;
                    oddLength++;
                }
                else{
                    evenSum += (long)temp;
                    evenLength++;
                }
            }

            if(oddSum%oddLength != 0 || evenSum%evenLength != 0 || (oddSum/oddLength != evenSum/evenLength)){
                System.out.println("NO");
            }
            else{
                System.out.println("YES");
            }
        }
    }
}