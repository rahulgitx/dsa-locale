#include <bits/stdc++.h>
using namespace std;

int findmin(int arr[], int n, int k){
    int l, r, mincount=INT_MAX;
    for(int l=0; l<n-k+1; l++){
        r=l+k-1;
        cout << "l: " << l << " r: " << r << endl;
        int onecount = 0;
        for(int j=l; j<=r; j++){
            if(arr[j] == 1){
                onecount++;
            }
        }
        mincount = min(mincount, onecount);
    }
    return mincount;
}

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    int arr[n];
    memset(arr, 0, sizeof(arr));
    int temp;
    for(int i=0; i<q; i++){
        cin >> temp;
        arr[temp-1] = 1; 
    }
    // for(int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    cout << findmin(arr, n, k);
}

/*
10 6 5
2
10
1
5
9
ans=1
*/

/*
13 8 5
1 4 7 10 13
*/