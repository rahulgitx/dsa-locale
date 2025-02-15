import java.util.*;

public class BeautifulMatrix{
    public static int diff(int a, int b){
        if(a > b) return a-b;
        return b-a;
    }
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);

        int[][] matrix = new int[5][5];
        int r = 0, c = 0;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                matrix[i][j] = scanner.nextInt();
                if(matrix[i][j] == 1){
                    r = i; c = j;
                }
            }
        }

        int res = 0;
        res += diff(r,2) + diff(c,2);
        System.out.println(res);
    }
}