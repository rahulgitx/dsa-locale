import java.util.*;

public class D{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        
        while(t > 0){
            t--;

            int n = scanner.nextInt();
            int d = scanner.nextInt();
            int k = scanner.nextInt();

            int[] endings = new int[n];
            int[] startings = new int[n];
            for(int i=0; i<k; i++){
                int l = scanner.nextInt();
                int r = scanner.nextInt();
                startings[l-1]++;
                endings[r-1]++;
            }
            // for(int i=0; i<n; i++){
            //     System.out.print(startings[i] + " ");
            // }
            // System.out.println();
            // for(int i=0; i<n; i++){
            //     System.out.print(endings[i] + " ");
            // }
            // System.out.println();

            int countB = Integer.MIN_VALUE, countM = Integer.MAX_VALUE;
            int resM =0, resB = 0;

            int l = n-d, r = n-1, jCount = 0;
            for(int i=n-1; i>=Math.max(0, n-d); i--){
                jCount += endings[i];
            }

            while(l>=0){
                if(countM >= jCount){
                    countM = jCount;
                    resM = l+1;
                }
                if(countB <= jCount){
                    countB = jCount;
                    resB = l+1;
                }

                if(l-1 >=0){ 
                    // System.out.println("endings[l-1]: "+endings[l-1]);
                    jCount += endings[l-1];
                }
                // System.out.println("startings[r]: "+startings[r]);
                jCount -= startings[r];

                // System.out.println(l + ":" + r + " jCount: " + jCount + " mCount: " + countM + " bCount: " + countB);
                r--; l--;
            }
            System.out.println(resB + " " + resM);
        }
    }
}

/*
6
2 1 1
1 2
4 1 2
1 2
2 4
7 2 3
1 2
1 3
6 7
5 1 2
1 2
3 5
9 2 1
2 8
9 2 4
7 9
4 8
1 3
2 3

*/