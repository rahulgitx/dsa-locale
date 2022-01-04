#include <bits/stdc++.h>
using namespace std;


// self-made approach
int selfsumdp(vector<int> &nums, int target){
    int sum = 0, maxim = -1;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        maxim = max(maxim, nums[i]);
    }
    if(target > sum || target < -sum){
        return 0;
    }
    int range;
    if(sum > 0){
        range = 2*sum + 1;
    }
    else{
        range = 1;
    }
    cout << "range: " << range << "  sum: " << sum << endl;

    //initialising
    int **dp = new int*[nums.size()+1];
    for(int i=0; i<nums.size()+1; i++){
        dp[i] = new int[range + 2*maxim];
        for(int j=0; j<range + 2*maxim; j++){
            dp[i][j] = 0;
        }
    }
    dp[nums.size()][0+maxim] = 1;
    dp[nums.size()][range-1+maxim] = 1;
    dp[0][range/2 + maxim] = 1;



    for(int i=1; i<nums.size()+1; i++){
        for(int j=1+maxim; j<range-1+maxim; j++){
            dp[i][j+maxim] = dp[i-1][j-nums[i-1]+maxim] + dp[i-1][j+nums[i-1]+maxim]; 
            cout << "dp[" << i << "][" << j-sum+maxim << "]: " << dp[i][j+maxim] << " ";
        }
        cout << endl;
    }
    // cout << "out of loop";
    cout <<  "dp[nums.size()][rang-target+maxim] : dp[" << nums.size() << "][" << range-target+maxim << "]: " << dp[nums.size()][range-target+maxim];
    // int outnum = 
    return dp[nums.size()][target - (-sum) + maxim];

}

int targetsumdp(vector<int> &nums, int target){
    int sum = 0;
    int zerocount = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(i < nums.size() && nums[i] == 0){
            zerocount++;
        }
    }
    int mid = sum/2;
    cout << "sum: " << sum << " mid: " << mid << endl;

    //initialization

    int **dp = new int*[nums.size()+1];
    for(int i=0; i<nums.size()+1; i++){
        dp[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++){
            if(j == 0){
                // if(i > 0 && nums[i-1] == 0){
                //     zerocount++;
                //     dp[i][j] = pow(2, zerocount);
                // }
                // else{
                    dp[i][j] = 1;
                // }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[0][0] << endl;

    if(target < 0){
        target = -target;
    }

    for(int i=1; i<nums.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            if(nums[i-1] == 0 || nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
            // else{
            //     dp[i][j] = dp[i-1][j];
            // }
            cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << " ";
        }
        cout << endl;
    }

    int ans = 0;
    for(int i=0; i<=mid; i++){
        if(dp[nums.size()][i] > 0){
            if(sum-2*i == target){
                ans = min(dp[nums.size()][i], dp[nums.size()][sum-i]) ;
            }
        }
    }
    cout << "zerocount: " << zerocount << endl;
    return ans*pow(2, zerocount);

}


 int findTargetSumWays(vector<int>& nums, int S)

    {

        int cnt = 0,sum = 0;

        int n = nums.size();

        for(int i=0;i<nums.size();i++)

        {

            sum = sum+nums[i];

            if(nums[i]==0)

                cnt = cnt+1;

        }

        if(S > sum)

            return 0;

        if((S+sum)%2!=0)

            return 0;

        int s = (S+sum)/2;

        int dp[n+1][s+1];

        for(int i=0;i<n+1;i++)

            dp[i][0] = 1;

        for(int j=1;j<s+1;j++)

            dp[0][j] = 0;

        for(int i=1;i<n+1;i++)

        {

            for(int j=1;j<s+1;j++)

            {

                if(nums[i-1]==0)

                    dp[i][j] = dp[i-1][j];

                else if(j < nums[i-1])

                    dp[i][j] = dp[i-1][j];

                else

                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];

            }

        }

        

        return pow(2,cnt)*dp[n][s];

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