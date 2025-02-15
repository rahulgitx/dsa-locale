import java.util.*;

public class B{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while(t>0){
            t--;
            int k = scanner.nextInt();
            int prod = k-2;
            HashMap<Integer, Integer> mp = new HashMap<>();
            for(int i=0; i<k; i++){
                int num = scanner.nextInt();
                mp.put(num, mp.getOrDefault(num, 0)+1);
            }
            // System.out.println(mp.size());

            for(int i=1; i*i<=prod; i++){
                int a = i;
                if(prod%a != 0) continue;
                int b = prod/a;
                if(a==b && mp.containsKey(a) && mp.get(a)>1){
                    System.out.println(a + " " + b);
                    break;
                }
                else if(a != b && mp.containsKey(a) && mp.containsKey(b)){
                    System.out.println(a + " " + b);
                    break;
                }
            }
        }
    }
}