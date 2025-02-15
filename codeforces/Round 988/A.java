import java.util.*;

public class A{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while(t>0){
            t--;

            int n = scanner.nextInt();
            // int[] nums = new int[n];
            HashMap<Integer, Integer> mp = new HashMap<>();
            for(int i=0; i<n; i++){
                int num = scanner.nextInt();
                mp.put(num, mp.getOrDefault(num, 0)+1);
            }

            int res = 0;
            for(Map.Entry<Integer, Integer> entry : mp.entrySet()){
                // System.out.println(entry.getKey() + " " + entry.getValue());
                res += entry.getValue()/2;
            }
            System.out.println(res);
        }
    }
}