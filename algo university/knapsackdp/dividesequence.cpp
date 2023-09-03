#include <bits/stdc++.h>
using namespace std;

int func(long long int arr[], int n){
    int dp[n];
    dp[0] = 1;
    int maxval = 1;
    for(int i=1; i<n; i++){
        int found = 0;
        // cout << " i: " << i << endl;
        priority_queue<int> pq;
        for(int j=i-1; j>=0; j--){
            // cout << " j: " << j;
            if((arr[i])%(arr[j]) == 0){
                pq.push(dp[j]);
            }
        }
        // cout << " i: " << i << " pqtop: " << pq.top() << endl;
        if(!pq.empty()){
            dp[i] = pq.top()+1;
            found++;
        }
        else{
            dp[i] = 1;
        }
        maxval = max(dp[i], maxval);
    }
    // cout << maxval << endl;

    return maxval;
}

int solve(int arr[], int n){
    if(n <= 0){
        return n;
    }

    int a = solve(arr, n-1);
    int findex;
    for(int i=n-1; i>=0; i--){
        if(arr[n-1]%arr[i] == 0){
            findex = i;
            break;
        }
    }
    int b = 1+solve(arr, findex);
    return max(a, b);
}

int main(){
    int n;
    cin >> n;
    long long int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        // long long temp = i+1;
        // arr[i] = temp;
    }

    cout << func(arr, n);
}

/*
7
1 2 3 6 7 42 84
*/