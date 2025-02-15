import java.util.*;

public class A{
    
    public static long func(long n, long k, List<Long> power){
        if(k>n || k==1) return n;

        int i=0;
        while(power.get(i) <= n){
            i++;
        }
        i--;
        n = n-power.get(i);
        return 1+func(n,k, power);
    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while(t > 0){
            t--;

            long n = scanner.nextLong();
            long k = scanner.nextLong();
            
            long temp = 1;
            List<Long> list = new ArrayList<>();
            list.add(temp);
            while(k>1 && temp <= n){
                temp = list.get(list.size()-1)*k;
                list.add(temp);
            }
            // for(int i=0; i<list.size(); i++){
            //     System.out.print(list.get(i) + " ");
            // }
            // System.out.println();
            long res = func(n,k,list);
            System.out.println(res);
        }
    }
}

/*
6
5 2
3 5
16 4
100 3
6492 10
10 1
*/