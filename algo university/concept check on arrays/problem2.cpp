#include <bits/stdc++.h>
using namespace std;

int findmax(int arr[], int n){
    int maxim = 0;
    int prefsum[n];
    unordered_map<int, int> mp;
    prefsum[0] = arr[0];
    mp[prefsum[0]] = 0;
    
    for(int i=1; i<n; i++){
        prefsum[i] = prefsum[i-1]+arr[i];
        if(mp.count(prefsum[i]) == 0){
            mp[prefsum[i]] = i;
        }
    }
    unordered_map<int, int>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++){
        cout << it->first << " : " << it->second << endl;
    }
    for(int i=0; i<n; i++){
        if(prefsum[i]%7 == 0){
            maxim = i+1;
            cout << "prefsum: " << prefsum[i] << " " << "max: " << maxim << endl;
            
        }
        else{
            cout << "prefsum: " << prefsum[i] << " ";
            int temp = prefsum[i] - (prefsum[i]%7);
            while(temp > 0){
                cout << "temp: " << temp << " ";
                if(mp.count(prefsum[i] - temp) > 0){
                    maxim = max(maxim, i - mp[prefsum[i] - temp]);
                    cout << "maxim: " << maxim;
                    break;
                }
                else{
                    temp = temp-7;
                }
            }
        }
        cout << endl;

    }
    // if (maxim == 0){
    //     return -1;
    // // }
    for(int i=0; i<n; i++){
        cout << prefsum[i] << " ";
    }
    return maxim;



}

long long int func(long long int arr[], int n, int k){
        long long int maxim = 0;
        long long int prefsum[n];
        long long int diff[n];
        unordered_map<long long int, int> mp;
        prefsum[0] = arr[0];
        mp[prefsum[0]] = 0;
        diff[0] = prefsum[0]%k;
        
        for(int i=1; i<n; i++){
            prefsum[i] = prefsum[i-1]+arr[i];
            diff[i] = prefsum[i]%k;
    
        }
        // cout << endl;
    for(int i=0; i<n; i++){
        cout << prefsum[i] << " ";
    }
    cout << endl;

    for(int i=0; i<n; i++){
        cout << diff[i] << " ";
    }
    cout << endl;

    for(long long int i=0; i<n; i++){
        if(diff[i] == 0){
            maxim = max(maxim, i+1);
        }
        else if(mp.count(diff[i]) == 0){
            mp[diff[i]] = i;
        }
        else{
            maxim = max(maxim, i-mp[diff[i]]);
        }
    }
        return maxim;
	}


int main(){
    int n, k;
    cin >> n >> k;
    long long int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "ans" << func(arr, n, k);
}

/*
7 7
3 5 1 6 2 14 10
ans = 5
*/

/*
5 7
7 14 21 28 35
ans=5
*/

/*
10 7
0 1 0 2 3 4 5 3 3 7
ans=10
*/

/*
11 7
7 7 7 1 1 1 1 7 7 7 7
ans=4
*/

/*
14 7
7 1 7 1 7 1 7 1 7 1 7 1 7 1
ans=14
*/

/*
5 7
2 2 2 2 2
ans=0
*/


/*
10 7
2 2 0 0 0 0 0 7 7 7 7 
ans=8
*/

/*
7 7
0 0 0 7 0 0 0
ans=7
*/

/*
11  7
18 9 9 10 5 16 15 13 6 15 3
ans=10
*/

/*
13 1
20 13 11 14 2 7 4 2 6 7 6 13 6
ans=13
*/

/*
7 3
-2 2 -5 12 -11 -1 7
*/

/*
6 7
6 0 7 0 7 0 
*/

/*
8 7
7 0 6 0 7 0 7 0 
*/

/*
5 7
0 7 -7 5 -12
*/

/*
5 7
-7 -7 -7 -7 -7
*/

/*
6 5
4 5 0 -2 -3 1
*/

/*
1 7
8
ans=0
*/