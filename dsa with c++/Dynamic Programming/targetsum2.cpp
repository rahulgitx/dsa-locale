#include <bits/stdc++.h>
using namespace std;

int targetsumdp(vector<int> nums, int target){
    int sum = 0;
    int zerocount=0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(nums[i] == 0){
            zerocount++;
        }
    }
    int mid = sum/2 + sum%2;

    // initialisation
    int** dp = new int*[nums.size()+1];
    for(int i=0; i<nums.size()+1; i++){
        dp[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++){
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(j>0 && i== 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    for(int i=1; i<nums.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            if(j >= nums[i-1]){
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    

    //print
    for(int i=0; i<nums.size()+1; i++){
        for(int j=0; j<sum+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "sum: " << sum << " mid: " << mid << endl;


    int ans=0;
    for(int i=0; i<mid; i++){
        cout << sum-2*i << " " ;
        if(sum - 2*i == target){
            
            ans+=dp[nums.size()][i];
        }
    }
    return ans*pow(2,zerocount);
}


int main(){
    int n, target; 
    cin >> n >> target;
    int temp;
    vector<int> nums;
    for(int i=0; i<n; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    
    cout << endl << targetsumdp(nums, target);
}


/*
5 3
1 1 1 1 1
ans = 5
*/

/*
1 1 
1 
ans=1
*/

/*
2 1
1 0
ans = 2
*/

/*
2 1
1 0
*/

/*
1 1000
1000
ans=1
*/

/*
1 -1000
1000
ans=1
*/

/*
9 1
0 0 0 0 0 0 0 0 1
ans=256
*/

/*
10 6
7 0 3 9 9 9 1 7 2 3
ans=50
*/

/*
4 1
1 1 2 3
ans = 
*/