// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

int minvect(vector<int> v){
    int minval = v[0];
    for(int i=0; i<v.size(); i++){
        if (minval > v[i]){
            minval = v[i];
        }
    }
    return minval;
}


//dynamic programming approach
int minstepdp(int n){
    int *arr = new int[n+1];
    for(int i=1; i<n+1; i++){
        arr[i] = -1;
    }
    arr[1] = 0;
    if(n == 1){
        return 0;
    }

    for(int i=2; i<n+1; i++){
        // vector<int> possil;
        int x = INT_MAX, y = INT_MAX;
        if(i%3 == 0){
            x = (1+arr[i/3]);
        }
        if(i%2 == 0){
            y = (1+arr[i/2]);
        }
        int z = (1+arr[i-1]);
        arr[i] = min (x, min(y, z));
    }
    return arr[n];

}

//memoization
int minstephelper(int n, int *arr){
    if(arr[n] != -1){
        return arr[n];
    }
    else{
        if(n == 1){
            arr[n] == 0;
            return 0;
        }
        if(n <= 3){
            arr[n] = 1;
            return 1;
        }
        else{
            vector<int> possibl;
            if(n%3 == 0){
                possibl.push_back(1+minstephelper(n/3, arr));
            }
            if(n%2 == 0){
                possibl.push_back(1+minstephelper(n/2, arr));
            }
            possibl.push_back(1+minstephelper(n-1, arr));
            arr[n] = minvect(possibl);
            return arr[n];
        }
    }
}

int minstepmemo(int n){
    int *arr = new int[n+1];
    for(int i=1; i<=n; i++){
        arr[i] = -1;
    }

    return minstephelper(n, arr);

}

//brute force
int minstepto1(int n){
    if(n == 1){
        return 0;
    }
    if(n <= 3){
        return 1;
    }
    else{
        vector<int> possibl;
        if(n%3 == 0){
            possibl.push_back(1+minstepto1(n/3));
        }
        if(n%2 == 0){
            possibl.push_back(1+minstepto1(n/2));
        }
        possibl.push_back(1+minstepto1(n-1));
        return  minvect(possibl);
    }
}


int main(){
    int t;
    cin >> t;
    int arr[t];
    for(int i=0; i<t; i++){
        cin >> arr[i];
    }

    for(int i=0; i<t; i++){
        cout << minstepdp(arr[i]) << endl;
    }
}

/*
2
4
10
ans=2 3
*/

/*
2
6
12
ans=2 3
*/