import java.util.*;

public class F{
    public static boolean validAns(int n, int m, int k, int[] h, int[] x, int maxMoves){
        List<Integer[]> boundaries = new ArrayList<>();
        for(int i=0; i<n; i++){
            int hi = (h[i] + maxMoves -1)/maxMoves;  // ceil of h[i]/maxMoves

            if(hi > m) continue;

            int pstart = hi + x[i] - m;
            int pend = m + x[i] - hi;
            // System.out.println("hi:"+hi + " st:" + pstart + " en:" + pend);

            boundaries.add(new Integer[]{pstart, 1});
            boundaries.add(new Integer[]{pend, -1});
        }
        Collections.sort(boundaries, (a, b) -> {
            if(a[0].equals(b[0])) return b[1]-a[1];
            return a[0]-b[0];
        });

        int enemiesDefeated = 0;
        for(int i=0; i<boundaries.size(); i++){
            enemiesDefeated += boundaries.get(i)[1];
            // if(maxMoves==2){
            //     System.out.println(enemiesDefeated);
            // }
            if(enemiesDefeated >= k) return true;
        }
        return false;
    }
    public static void main(String...args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for( ; t>0; t--){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int k = sc.nextInt();
            int[] h = new int[n];
            int[] x = new int[n];
            for(int i=0; i<n; i++){
                h[i] = sc.nextInt();
            }
            for(int i=0; i<n; i++){
                x[i] = sc.nextInt();
            }

            int res = -1;
            int low = 1, high = 1000000000;
            while(low<=high){
                int mid = low + (high-low)/2;
                // System.out.println("mid: " + mid);
                if(validAns(n,m,k,h,x,mid)){
                    res = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            System.out.println(res);
        }
    }
}