#include <bits/stdc++.h>
using namespace std;

long long min(long long a, int b){
    if(a > b){
        return b;
    }
    return a;
}
long long max(long long a, int b){
    if(a > b){
        return a;
    }
    return b;
}

long long circular(vector<int> arr){
    int n = arr.size();
    long long int prevsmall = arr[0],  minval = arr[0], sum = arr[0];
    long long prevlarge = arr[0], maxval = arr[0];
    int  greatest = arr[0];
    for(int i=1; i<n; i++){
        sum += arr[i];
        prevsmall = min(arr[i], prevsmall+arr[i]);
        minval = min(minval, prevsmall);

        prevlarge = max(arr[i], prevlarge+arr[i]);
        maxval = max(maxval, prevlarge);

        greatest = max(greatest, arr[i]);
    }

    // cout << "minval: " << minval << " greatest: " << greatest << " sum: " << sum << endl;

    if(minval == sum){
        return greatest;
    }

    return max(maxval, sum - minval);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    cout << circular(arr);
}

/*
6
-1 4 -1 -2 -3 -4
*/

/*
5
-1 -2 -3 -4 -5
*/

/*
5
1 2 3 4 5
*/


