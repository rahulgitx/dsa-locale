#include <bits/stdc++.h>
using namespace std;
int numberOfCows(vector<int>& stalls, int minDistance){
    int n = 1, lastPosition = stalls[0];
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i]-lastPosition >= minDistance){
            n++;
            lastPosition = stalls[i];
        }
    }
    return n;
}
int aggressiveCows(vector<int>& stalls, int c){
    int low=0, high=1e9;
    int res;
    while(low <= high){
        int mid = low + (high-low)/2;

        // get no of cows that can be placed if we assume the mininum distance to be "mid"
        int noOfCows = numberOfCows(stalls, mid);

        if(noOfCows < c){
            high = mid-1;
        }
        else{
            res = mid;
            low = mid+1;
        }
    }
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> v(n, 0);
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            v[i] = temp;
        }
        sort(v.begin(), v.end());
        cout << aggressiveCows(v, c);
        if(t) cout << endl;
    }
}

/*
3
5 3
1
2
8
4
9
5 3
0
1
2
3
4
2 2
0
1
*/