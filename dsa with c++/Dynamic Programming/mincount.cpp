#include <bits/stdc++.h>
using namespace std;


// dp approach
int mincountdp(int n){
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }
    if(n <= 1){
        return n;
    }
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2; i<=n; i++){
        int sq = pow(i, 0.5);
        int temp;
        arr[i] = INT_MAX;
        for(int j=1; j<=sq; j++){
            temp = 1+arr[i-(j*j)];
            if(arr[i] > temp){
                arr[i] = temp;
            }
        }
    }

    return arr[n];
}

// memoisation
int helper(int *arr, int n){
    if(arr[n] != -1){
        return arr[n];
    }
    
    int sq = pow(n, 0.5);
    int minum = INT_MAX;
    int temp;
    for(int i=1; i<=sq; i++){
        temp = 1+helper(arr, n-(i*i));
        if(minum > temp){
            minum = temp;
        }
    }
    arr[n] = minum;
    return minum;
}

int mincountmemo(int n){
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }

    if(n <= 1){
        return n;
    }
    arr[0] = 0;
    arr[1] = 1;

    return helper(arr, n);
}


//brute force 
int mincount(int n){
    if(n <= 1){
        return n;
    }
    int sq = pow(n, 0.5);
    int minnum = INT_MAX;
    int temp;
    for(int i=1; i<=sq; i++){
        temp = 1+mincount(n-(i*i));
        if(minnum > temp){
            minnum = temp;
        }
    }
    return minnum;
}

int main(){
    int n;
    cin >> n;
    cout << mincountdp(n);

}