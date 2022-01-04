#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n, int k){
    int rotated[n];
    for(int i=k; i<n; i++){
        rotated[i-k] = arr[i]; 
    }
    for(int i=0; i<k; i++){
        rotated[i+n-k] = arr[i]; 
    }
    for(int i=0; i<n; i++){
        cout << rotated[i] << " ";
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    rotate(arr, n, k);
}

/*
4 2
1 2 3 4
*/

/*
7 2
1 2 3 4 5 6 7
*/