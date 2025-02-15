#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& v, int val){
    int low=0, high=v.size()-1, mid, index=0;
    while(low <= high){
        mid = low + (high-low)/2;

        if(val <= v[mid]){
            index = mid;
            high = mid-1;
        }
        else if(val > v[mid]){
            index = mid+1;
            low = mid+1;
        }
    }
    return index;
}

int lis(vector<int> arr){
    vector<int> v;
    // v.push_back(arr[0]);
    for(int i=0; i<arr.size(); i++){
        int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        // int index = lowerBound(v, arr[i]);
        cout << index << " size: " << v.size() << endl;
        if(index >= v.size()) v.push_back(arr[i]);
        else v[index] = arr[i];
    }
    return v.size();
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    // cout << lowerBound(arr,7);
    cout << lis(arr);
    // cout << lower_bound(arr.begin(), arr.end(), 0) - arr.begin();
}
/*
8
1 7 8 4 5 6 -1 9
*/
/*
9
1 3 5 8 8 8 10 20 25
*/