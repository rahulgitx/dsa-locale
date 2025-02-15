import java.util.*;

public class C{
    int sol(int[][] cords){
        HashSet<Long> set = new HashSet<>();
        HashMap<Long, List<Long>> mp = new HashMap<>();
        for(int i=0; i<cords.length; i++){
            int x = cords[i][0], y = cords[i][1];
            long hsh = (long)(x*100000l) + (long)y;
            x--; y--;
            for(int j=x; j<x+3; j++){
                for(int k=y; j<y+3; j++){
                    long chsh = (long)j*100000l + (long)k;
                    List<Long> list = mp.getOrDefault(chsh, new ArrayList<>());
                    list.add(hsh);
                }
            }
        }
        int res = 0;
        for(Map.Entry<Long, List<Long>> entry : mp.entrySet()){
            List<Long> list = entry.getValue();
            int n = list.size();
            res += (n*(n-1))/2;
        }
        return res;
    }
    public static void main(String...args){
        C a = new C();
        int[][] cord = new int[3][];
        cord[0] = new int[]{1,1};
        cord[1] = new int[]{2,2};
        cord[2] = new int[]{0,4};
        System.out.println(a.sol(cord));
        System.out.println("hello");
    }
}