#include <bits/stdc++.h>
using namespace std;

// int lowerBound(vector<int>& v, int val){
//     int low = 0, high = v.size()-1, mid, index;
//     while(low<=high){
//         mid = low + (high-low)/2;
//         cout << low << ":" << mid << ":" << high << endl;
//         if(val < v[mid]){
//             index = mid;
//             high = mid-1;
//         }
//         else if(val >= v[mid]){
//             low = mid+1;
//             index = low;
//         }
//     }
//     return index;
// }

int upperBound(vector<int>& v, int val){
    int low = 0, high = v.size()-1, mid, index;
    while(low<=high){
        mid = low + (high-low)/2;
        // cout << low << ":" << mid << ":" << high << endl;
        if(val <= v[mid]){
            high = mid-1;
            index = high;
        }
        else if(val > v[mid]){
            index = mid;
            low = mid+1;
        }
    }
    return index;
}

long long countPairs(vector<int>& left, vector<int>& right){
    long long count = 0;
    // cout << "counting for ";
    // for(int i=0; i<left.size(); i++) left[i];
    // cout << " and ";
    // for(int i=0; i<right.size(); i++) right[i];
    // cout << " ";
    for(int i=0; i<left.size(); i++){
        int index = upperBound(right, left[i]);
        if(index >= 0) count += index+1;
    }
    // cout << count << endl;
    return count;
}

vector<int> merge(vector<int>& a, vector<int>& b){
    if(a.size()==0) return b;
    else if(b.size() == 0) return a;
    int i=0, j=0;
    vector<int> merged;
    while(i<a.size() || j<b.size()){
        if(j>=b.size()){
            merged.push_back(a[i]);
            i++;
        }
        else if(i>=a.size()){
            merged.push_back(b[j]);
            j++;
        }
        else if(a[i]<b[j]){
            merged.push_back(a[i]);
            i++;
        }
        else if(a[i] >= b[j]){
            merged.push_back(b[j]);
            j++;
        }
    }
    return merged;
}
vector<int> func(vector<int> nums, int low, int high, long long& ans){
    if(low >= high){
        vector<int> v;
        if(low > high) return v;
        v.push_back(nums[low]);
        return v;
    }
    int mid = low + (high-low)/2;
    vector<int> left = func(nums,low,mid, ans);
    vector<int> right = func(nums,mid+1, high, ans);

    // cout << low << ":" << mid << " " << mid+1 << ":" << high << " ";
    ans += countPairs(left, right);


    return merge(left, right);
}

int main(){
    int n, temp; cin >> n;
    vector<int> a,b; 
    for(int i=0; i<n; i++){
        cin >> temp;
        a.push_back(temp);
    }
    // cin >> n;
    // for(int i=0; i<n; i++){
    //     cin >> temp;
    //     b.push_back(temp);
    // }
    // countPairs(a, b);


    int ans = 0;
    func(a, 0, a.size()-1, ans);
    cout << ans;
}

/*

4
0 2 6 10
3
1 5 9
5
2 5 1 3 4
10
52244275 123047899 493394237 922363607 378906890 188674257 222477309 902683641 860884025 339100162
*/

/*
2
2 5
1
1
*/