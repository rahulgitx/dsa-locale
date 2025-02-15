import java.util.*;

public class A{
    String[] sol(String[] ids, String[] chats){
        Map<String, Integer> mp = new TreeMap<>();
        for(String s : ids){
            mp.put(s, 0);
        }

        for(String s : chats){
            int j=0, n = s.length();
            while(j<n){
                if(s.charAt(j)==' '){
                    j++;
                    continue;
                }
                StringBuilder temp = new StringBuilder();
                if(s.charAt(j)=='@') j++;

                while(j<n && s.charAt(j)!=' '){
                    temp.append(s.charAt(j));
                    j++;
                }

                j++;
                String t = temp.toString();
                System.out.println(t);
                if(mp.containsKey(t)) mp.put(t, mp.get(t)+1);
            }
        }

        String[] res = new String[mp.size()];
        int i = 0;
        for(Map.Entry<String, Integer> entry : mp.entrySet()){
            StringBuilder str = new StringBuilder();
            // str.append("[");
            str.append(entry.getKey());
            str.append("=");
            str.append(Integer.toString(entry.getValue()));
            // str.append(']');
            res[i] = str.toString();
            System.out.println(res[i]);
            i++;
        }
        i=0;
        int j = res.length-1;
        // while(i<=j){
        //     String temp = res[i];
        //     res[i] = res[j];
        //     res[j] = temp;
        //     i++; j--;
        // }
        return res;

    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        String[] ids = new String[]{"id1","id23","id3"};
        String[] chats = new String[]{"hey @id1", "hey my man @id23"};
        A a = new A();
        System.out.println(a.sol(ids, chats));
        System.out.println("hello");
    }
}