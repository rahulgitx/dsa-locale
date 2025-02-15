import java.util.*;

public class GiftRyt{
    boolean canCompleteCourse(int[] arr){
        int n = arr.length;
        boolean[] dp = new boolean[n];

        dp[n-1] = true;
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<=Math.min(arr.length-1, i+arr[i]); j++){
                if(dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
    public static void main(String...args){
        
    }
}

/*
noOfCourses = 3, int[][] arr = [[0,1],[1,2]]
0 <- 1 , 1 <- 2

n = 2, int[][] arr = [[0,1],[1,0]]




int[] arr  = [3,2,1,0,4]
*/