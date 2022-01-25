#include <bits/stdc++.h>
using namespace std;

void hashmap(int n, int m, long long int arr[]){
    long long int hmap[m];
    // memset(hmap, -1, sizeof(hmap));
    for(int i=0; i<m; i++){
        hmap[i] = -1;
    }
    // for(int i=0; i<m; i++){
    //     cout << hmap[i] << " ";
    // }
    int temp;
    // unordered_map<int, int> mods;
    unordered_map<int, int> duplicacy;
    for(int i=0; i<n; i++){
        int mod = arr[i]%m;
        if(duplicacy.count(mod) == 0){
            duplicacy[mod] = arr[i];
        }
        else{
            continue;
        }
        // if(check.count(arr[i]) > 0){
        //     continue;
        // }
        // temp = arr[i]%m;
        // if(hmap[temp] != -1){
        //     while(hmap[temp] != -1 && temp <= m){
        //         temp++;
        //     }
        // }
        // if(temp > m-1){
        //     continue;
        // }
        // hmap[temp] = arr[i];
        // // cout << arr[i] << " -> " << hmap[temp] << endl;
        // check[arr[i]]++;
    }
    unordered_map<int, int>::iterator it;
    for(it = duplicacy.begin(); it != duplicacy.end(); it++){
        // cout << it->first >> " -> " << it->second << endl;
        hmap[it->first] = it->second;
    }
    for(int i=0; i<m; i++){
        cout << hmap[i] << " ";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    long long int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    hashmap(n, m, arr);
}

/*
9 5
12 7 22 2 4 2 1 3 5
*/