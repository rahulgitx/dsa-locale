#include <bits/stdc++.h>
using namespace std;

//dp approach
int countofbtsdp(int n){
    if(n <= 1){
        return 1;
    }
    
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }
    arr[0] = 1;
    arr[1] = 1;

    int x,y;
    for(int i=2; i<=n; i++){
        x = arr[i-1];
        y = arr[i-2];
        arr[i] = (x*x + x*y + y*x);
    }
    return arr[n];
}


//memoisation
int helper(int n, int *arr){
    if(arr[n] != -1){
        return arr[n];
    }
    
    int x = helper(n-1, arr);
    int y = helper(n-2, arr);
    arr[n] = (x*x + x*y + y*x);
    return arr[n];
}

int countofbtsmemo(int n){
    if(n <= 1){
        return 1;
    }
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }

    arr[0] = 1;
    arr[1] = 1;

    return helper(n, arr);
    
}

//brute force solution
int countofbts(int n){
    if(n <= 1){
        return 1;
    }
    int x = countofbts(n-1);
    int y = countofbts(n-2);
    return (x*y + x*y + x*x);
}

int main(){
    int n;
    cin >> n;
    cout << countofbtsdp(n);
}