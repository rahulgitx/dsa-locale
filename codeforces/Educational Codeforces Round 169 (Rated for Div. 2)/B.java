import java.util.*;

public class B{
    public static void main(String...args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0){
            t--;

            Integer[][] arr = new Integer[2][2];

            arr[0][0] = scanner.nextInt();
            arr[0][1] = scanner.nextInt();
            arr[1][0] = scanner.nextInt();
            arr[1][1] = scanner.nextInt();

            Comparator<Integer[]> comp = (a, b) -> {
                if(a[0] > b[0]) return 1;
                else if(a[0] == b[0]){
                    if(a[1] > b[1]) return 1;
                    else return -1;
                }
                return -1;
            };
            Arrays.sort(arr, comp);

            if(arr[0][1] < arr[1][0]){
                System.out.println(1);
            }
            else{
                if(arr[0][1] <= arr[1][1]){
                    int overlap = arr[0][1]-arr[1][0];

                    if(arr[0][0] < arr[1][0]) overlap++;
                    if(arr[0][1] < arr[1][1]) overlap++;

                    System.out.println(overlap);
                }
                else{
                    System.out.println(arr[1][1]-arr[1][0] + 2);
                }
            }
        }
    }
}

/*
5
1 2
3 4
2 5
2 5
3 7
6 7
4 5
2 8
13 15
13 19

*/