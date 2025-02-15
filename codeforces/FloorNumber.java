import java.util.*;

public class FloorNumber{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t > 0){
            t--;

            int n = scanner.nextInt();
            int x = scanner.nextInt();

            int floor = 1;
            n -= 2;
            while(n > 0){
                n -= x;
                floor++; 
            }
            System.out.println(floor);
        }
    }
}