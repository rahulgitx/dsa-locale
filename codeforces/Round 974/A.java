import java.util.*;

public class A{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t > 0){
            t--;

            int n = scanner.nextInt();
            int k = scanner.nextInt();
            
            int gold = 0, poor = 0, res = 0;
            for(int i=0; i<n; i++){
                int money = scanner.nextInt();
                if(money == 0){
                    if(gold > 0) {
                        gold--; res++;
                    }
                }
                else if(money >= k) gold += money;
            }

            System.out.println(res);
        }
    }
}