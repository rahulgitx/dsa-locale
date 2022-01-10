#include <bits/stdc++.h>
using namespace std;

int bsearch(long long int k, int arr[], int n){
    int left = 0;
    int right = n-1;
    int mid = (left+right)/2;
    cout << "k: " << k << endl;
    if(k > arr[right]){
        return 0;
    }
    while(left<=right){
        mid = left+ (right-left)/2;
        cout << "left: " << left << " mid: " << mid << " right: " << right << endl;
        if (right-left == 1){
            return n-right;
        }
        else if(left == right){
            if(arr[left-1] < arr[left]){
                return n-left;
            }
            else{
                return n-left+1;
            }
        }
        if(arr[mid] == k){
            if(arr[mid-1]<k){
                return n-mid;
            }
            else{
                right = mid;
            }
        }
        else if(arr[mid] > k){
            right = mid;
        }
        else{
            left = mid;
        }
    }
}

int main(){
    int n; 
    cin >> n;
    int arr[n];
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        // if(temp == 0){
        //     continue;
        // }
        arr[i] = temp;
    }

    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    long long int ncr;
    if(n == 3){
        ncr = 1;
    }
    else if(n < 3){
        cout << 0;
        return 0;
    }
    
    else{
        ncr = (n*(n-1)*(n-2))/6;
    }
    cout << "ncr:" << ncr << endl;

    long long int count = 0;
    // int sidesum;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x = bsearch(arr[i]+arr[j], arr, n);
            cout << "x: " << x << endl;
            count += x;
            cout << "count: " << count << endl;
        }
    }   
    cout << "count: " << count << endl;
    cout << ncr-count;
}

/*
5
10 6 8 6 4
ans=8
*/

/*
4
1 2 3 4
ans = 1
*/


/*
3
1 1 7
*/

/*
12
1 1 1 1 1 1 1 7 7 7 7 7
*/

/*
10
22 11 21 5 1 17 8 1 10 10
ans=33
*/

/*
14
5 19 20 6 10 18 22 17 4 18 27 22 19 26
ans=251
*/

/*
4
6 6 6 6
*/
