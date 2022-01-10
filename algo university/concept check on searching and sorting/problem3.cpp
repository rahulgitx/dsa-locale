#include <bits/stdc++.h>
using namespace std;

unsigned long long int findmin(unsigned long long int arr[], unsigned long long int n, long long int m){
    unsigned long long int maxim = 0, sum=0;
    for(int i=0; i<n; i++){
        maxim = max(arr[i], maxim);
        sum += arr[i];
    }
    cout << "maxim: " << maxim << " sum: " << sum << endl;

    unsigned long long int lastans = 0, left = maxim, right = sum;
    // int mid;
    while(left <= right){
        unsigned long long int mid = left + (right-left)/2;
        
        unsigned long long int count = 1, nosections = 0, currsecsum = 0;
        for(int i=0; i<n; i++){
            if((currsecsum + arr[i]) > mid){
                count++;
                currsecsum = arr[i];
            }
            else{
                currsecsum += arr[i];
            }
        }
        cout  << " l: " << left << " mid: " << mid << " r: " << right << " count: " << count << endl;
        if(count < m){   // we have to 
            right = mid-1;
        }
        else if(count > m){     // we have to no of sections -> we have to reduce mid
            left = mid+1;
        }
        else{
            lastans = mid;
            right = mid-1;
        }
    }
    if(lastans == 0){
        return maxim;
    }
    return lastans;
}

int main(){
    unsigned long long int n, m;
    cin >> n >> m;
    unsigned long long int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << findmin(arr, n, m);
}

/*
4 2
12 34 67 90
ans=113
*/

/*
6 4
10 7 8 12 6 8
ans=15
*/

/*
4 4
6 5 5 5
ans=6
*/

/*
5 5
6 6 6 5 6
*/

/*
6 2
6 6 6 5 6 6
*/

/*
6 4
1 3 4 6 2 8
ans=8
*/

/*
6 4
10 8 8 12 6 8
*/

/*
7 4
1 1 1 8 1 1 1
*/