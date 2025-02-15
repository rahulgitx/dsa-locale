import java.util.*;

public class B{
    public static void main(String...args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for(; t>0; t--){
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] nums = new int[n];
            HashMap<Integer, Integer> freq = new HashMap<>();
            for(int i=0; i<n; i++){
                nums[i] = sc.nextInt();
                freq.put(nums[i], freq.getOrDefault(nums[i], 0)+1);
            }

            int[] arr = new int[freq.size()];
            int j = 0;
            for(Map.Entry<Integer, Integer> entry : freq.entrySet()){
                arr[j] = entry.getValue(); j++;
            }

            Arrays.sort(arr);

            n = arr.length;
            int res = 1;
            for(int i=0; i<arr.length-1; i++){
                // System.out.println(k + " " + arr[i]);
                if(k>=arr[i]){
                    k -= arr[i];
                }
                else{
                    res = n-i;
                    break;
                }
            }
            System.out.println(res);
        }
    }
}