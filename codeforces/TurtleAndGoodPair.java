import java.util.*;

public class TurtleAndGoodPair{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while(t>0){
            t--;
            int n = scanner.nextInt();
            String s = scanner.next();

            int[] freq = new int[26];
            for(int i=0; i<n; i++){
                freq[s.charAt(i)-'a']++;
            }

            Comparator<Integer[]> comp = (a, b) -> {
                if(a[1] > b[1]) return 1;
                return -1;
            };
            // PriorityQueue<Integer[]> pq = new PriorityQueue<>(comp);
            // for(int i=0; i<26; i++) if(freq[i] > 0) pq.add(new Integer[]{i, freq[i]});

            StringBuilder str = new StringBuilder();
            int charsCountLeft = 1;
            while(charsCountLeft > 0){
                charsCountLeft = 0;
                for(int i=0; i<26; i++){
                    if(freq[i] > 0){
                        str.append((char)('a'+i));
                        freq[i]--;
                    }
                    charsCountLeft += freq[i];
                }
            }
            System.out.println(str);
        }
    }

    class Pair<T, K>{

    }
}