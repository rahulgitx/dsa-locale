// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    void helper(int a, int b, int x, int y, int nos, int** visited, int& ans, int arri[], int arrj[], int n){
        if(a == x && b == y){
            ans = min(ans, nos);
            // cout << " found ";
            return;
        }
        
        for(int k=0; k<8; k++){
            int i = a + arri[k];
            int j = b + arrj[k];
            // cout << " k:" << k << " i: " << i << " j: " << j << " n:" << n << " ";

            // cout << visited[i][j];
            if(i>=0 && j>=0 && i<n && j<n && (visited[i][j] == 0)){
                // cout << "loop" << ":nos " << nos+1 ;
                visited[i][j] = 1;
                helper(i, j, x, y, nos+1, visited, ans, arri, arrj, n);
                visited[i][j] = 0;
            }
            // else{
            //     cout << " cntd ";
            // }
        }
        return;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	   // priority_queue<int> pq;
	    int** visited = new int*[n];
	    for(int i=0; i<n; i++){
	        visited[i] = new int[n];
	        for(int j=0; j<n; j++){
	            visited[i][j] = 0;
	        }
	    }
	    int a = KnightPos[0]-1, b = KnightPos[1]-1;
	    int x = TargetPos[0]-1, y = TargetPos[1]-1;
	    visited[a][b] = 1;
	    // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << endl;
        // }


	    int arri[8] = {-2,-1,1,2,-2,-1,1,2};
	    int arrj[8] = {-1,-2,-2,-1,1,2,2,1};
	    
	    int ans = INT_MAX;
	    
	    helper(a, b, x, y, 0, visited, ans, arri, arrj, n);
		if(ans == INT_MAX){
			ans = 0;
		}
	    return ans;
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc=1;
	// cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

/*
6
1 1
4 5
*/

/*
8
4 5
1 1
*/

/*
2
1 1
1 2
*/
/*
3
1 1
2 2
*/
/*
4
1 1
4 4
*/