import java.util.*;

public class D{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0){
            t--;

            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int l = scanner.nextInt();

            int[][] hurdles = new int[n][2];
            for(int i=0; i<n; i++){
                hurdles[i][0] = scanner.nextInt();
                hurdles[i][1] = scanner.nextInt();
            }

            int[][] powerups = new int[m][2];
            for(int i=0; i<m; i++){
                powerups[i][0] = scanner.nextInt();
                powerups[i][1] = scanner.nextInt();
            }

            PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->{
                return b-a;
            });

            int i=0, j = 0;
            long jump = 1L;
            int res = 0;
            while(j<n){
                // System.out.println(i + " " + j + " " + powerups[i][0] + " " + hurdles[j][0]);
                while(i<m && powerups[i][0] < hurdles[j][0]){
                    pq.add(powerups[i][1]); i++;
                }
                long dist = (long)hurdles[j][1]-(long)hurdles[j][0]+2L;

                while(!pq.isEmpty() && jump < dist){
                    jump += (long)pq.poll();
                    res++;
                }
                // System.out.println(res + " " + jump);

                if(jump < dist){ 
                    res = -1;
                    break;
                }
                j++;
            }
            if(j<n-1) res = -1;
            System.out.println(res);
        }
    }
}