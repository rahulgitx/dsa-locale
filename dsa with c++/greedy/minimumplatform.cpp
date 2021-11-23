#include <bits/stdc++.h>
using namespace std;

int minplatform(int arr[], int dep[], int n){
    int minplat = 0;

    multimap<int, int> mp;
    for(int i=0; i<n; i++){
        mp.insert({arr[i], dep[i]});
    }

    // unordered_set<int> onstation;
    unordered_multimap<int, bool> onstation;
    for(auto it:mp){
        int currminplat = 1;
        // cout << it.first << endl;

        // for(auto itset=onstation.begin(); itset!=onstation.end();){
            for(auto itstation : onstation){

                // cout << "itset: " << *itset << endl;
                if(itstation.second && it.first < itstation.first){
                    // cout << "currmin++" << endl;
                    currminplat++;
                }
                if(itstation.second && it.first >= itstation.first){
                    // cout << "erased: " << *itset << " ";
                    // itset = onstation.erase(itset); 
                    itstation.second = false;
;                  
                }
                // else{
                //     itset++;
                // }


        }

        if(minplat < currminplat){
            minplat = currminplat;
        }

        // onstation.insert(it.second);
        onstation.insert({it.second, true});
    }
    return minplat;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    int dep[n];
    // int temp;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        cin >> dep[i];
    }
    
    cout << minplatform(arr, dep, n);
}

/*
6
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000
*/

/*
3
0900 1100 1235
1000 1200 1240
*/
