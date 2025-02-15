import java.util.*;

public class TheNewYearMeetingFriends{
    public static void main(String...args){
        int[] arr = new int[3];

        Scanner scanner = new Scanner(System.in);

        for(int i=0; i<3; i++){
            int temp = scanner.nextInt();
            arr[i] = temp;
        }
        Arrays.sort(arr);

        System.out.println(arr[2]-arr[1] +  arr[1]-arr[0]);
    }
}