#include <bits/stdc++.h>
using namespace std; 


// DP approach
int staircasedp(int n){
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }

    if(n <=2){
        arr[n] = n;
        return arr[n];
    }

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    for(int i=3; i<n+1; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

//memoisation
int staircasehelper(int n, int *arr){
    
    if(arr[n] != -1){
        return arr[n];
    }
    int x, y;
    x = staircasehelper(n-1, arr);
    y = staircasehelper(n-2, arr);
    return x+y;
}

int staircasememo(int n){
    int *arr = new int[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    if(n <= 2){
        return arr[n];
    }

    return staircasehelper(n, arr);
}


//brute force
int staircases(int n){
    if (n <= 2){
        return n;
    }
    int x, y;
    x = staircases(n-1);
    y = staircases(n-2);
    return x+y;
}

int main(){
    int n;
    cin >> n;
    cout << staircasememo(n);

}