#include <bits/stdc++.h>
using namespace std;

long long max(int a, long long b){
    if(a>b){
        return a;
    }
    return b;
}

long long kadane(int arr[], int n){
    long long maxval = arr[0];
    int prevmax=arr[0];
    for(int i=1; i<n; i++){
        prevmax = max(arr[i], prevmax+arr[i]);
        maxval = max(prevmax, maxval);
    }
    return maxval;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << kadane(arr, n);
}