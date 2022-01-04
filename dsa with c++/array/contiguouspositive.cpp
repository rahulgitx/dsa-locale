#include <bits/stdc++.h>
using namespace std;

vector<int> func(int arr[], int n, long long s){
      // Your code here
        vector<int> v;
        int i=0, j=0;
        long long sum = arr[i];
        while(j<n){
            if(arr[j] > s){  // when element is greater than sum
                j++;
                i=j;
                sum = arr[i];
                // cout << "i: " << i << " j: " << j << " sum: " << sum << " arr: " << arr[j] << endl;
            }
            else if(sum < s){
                j++;
                sum += arr[j];
                // cout << "i: " << i << " j: " << j << " sum: " << sum << " arr: " << arr[j] << endl;
            }
            else if(sum > s){
                sum -= arr[i];
                i++;
                // cout << "i: " << i << " j: " << j << " sum: " << sum << " arr: " << arr[j] << endl;
            }
            else{
                // cout << "i: " << i << " j: " << j << " sum: " << sum << " arr: " << arr[j] << endl;
                v.push_back(i+1);   
                v.push_back(j+1);
                return v;
            }
        }
        v.push_back(-1);
        return v;
}

int main(){
    int n;
    long long s;
    cin >> n; 
    cin >> s;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> v = func(arr, n, s);
    cout << v[0] << " " << v[1];
}

/*
5 12
1 2 3 7 5
ans: 2 4
*/

/*
10 15
1 2 3 4 5 6 7 8 9 10
ans: 1 5
*/

/*
51 150
193 55 70 82 66 68 114 194 35 73 173 31 102 43 178 78 171 103 165 182 191 24 38 24 180 196 170 128 43 111 183 59 127 88 71 129 52 59 14 61 184 87 143 11 73 129 35 42 119 104 68
*/