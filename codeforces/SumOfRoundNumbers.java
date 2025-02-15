import java.util.*;

public class SumOfRoundNumbers{
    public static void func(int n){
        List<Integer> list = new ArrayList<>();
        int m = 1;
        while(n>0){
            int temp = (n%10)*m;
            if(temp > 0) list.add(temp);
            m = m*10;
            n = n/10;
        }

        System.out.println(list.size());
        for(int i=0; i<list.size(); i++){
            System.out.print(list.get(i) + " ");
        }
        System.out.println();
    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while(t>0){
            t--;

            int n = scanner.nextInt();
            func(n);
        }
    }
}