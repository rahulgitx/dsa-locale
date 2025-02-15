import java.util.*;

public class C{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t > 0){
            t--;

            int n = scanner.nextInt();
            String s = scanner.next();
            int[] freq = new int[26];
            for(int i=0; i<s.length(); i++) freq[s.charAt(i)-'a']++;


            Integer[][] arr = new Integer[26][2];
            for(int i=0; i<26; i++){
                arr[i][0] = freq[i];
                arr[i][1] = i;
            }
            Comparator<Integer[]> comp = (a, b) -> {
                if(a[0] < b[0]) return 1;
                else if(a[0] == b[0]){
                    if(a[1] > b[1]) return 1;
                    else if(a[1] == b[1]) return 0;
                    return -1;
                }
                return -1;
            };
            Arrays.sort(arr, comp);

            StringBuilder str = new StringBuilder();
            for(int i=0; i<26; i++){
                for(int j=0; j<arr[i][0]; j++){
                    str.append((char)(arr[i][1]+'a'));
                }
            }
            System.out.println(str);
        }
    }
}