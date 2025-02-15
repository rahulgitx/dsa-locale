import java.util.*;

public class C{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0){
            t--;

            int n = scanner.nextInt();
            if(n<=4){
                System.out.println(-1);
                continue;
            }

            for(int i=1; i<=n; i++){
                if(i%2==1 && i!=5){
                    System.out.print(i + " ");
                }
            }
            System.out.print(5 + " ");
            System.out.print(4 + " ");
            for(int i=1; i<=n; i++){
                if(i%2==0 && i!=4){
                    System.out.print(i + " ");
                }
            }
            System.out.println();
        }
    }
}