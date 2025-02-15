import java.util.*;

public class RepeatingCipher{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        scanner.nextLine();
        String s = scanner.nextLine();

        int i=0, m = 1;
        StringBuilder res = new StringBuilder();

        while(i<s.length()){
            res.append(s.charAt(i));
            for(int j=0; j<m; j++){
                // System.out.println(i);
                i++;
            }
            m++;
        }
        System.out.println(res);
    }
}