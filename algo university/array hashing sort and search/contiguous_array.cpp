#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


// for returning the no of contiguous arrays
int myfunc(int arr[], int n, int x){
    int pref[n];
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
        pref[i] = sum;
    }
    unordered_map<int, int> mymap;
    mymap[0] = 1;
    int ans = 0; 
    for(int i=0; i<n; i++){
        int required = pref[i] - x;
        if (mymap.count(required) > 0){
            ans += mymap[required];
        }
        if (mymap.count(pref[i]) > 0){
            mymap[pref[i]] += 1;
        }
        else{
            mymap[pref[i]] = 1;
        }
    }
    return ans;
}

//for returning the contiguous arrays
void myfuncdisplay(int arr[], int n, int x){
    int pref[n];
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
        pref[i] = sum;
    }
    unordered_map<int, vector<int>> mymap;
    mymap[0].push_back(-1);
    // cout << mymap[0];
    for(int i=0; i<n; i++){
        int required = pref[i] - x;
        if (mymap.count(required) > 0){
            for (int j=0; j<mymap[required].size(); j++){
                cout << "{";
                for (int k = j+1; k<=i; k++ ){
                    cout << arr[k] << ",";
                }
                cout << "}" << endl;
            }
        }
        mymap[pref[i]].push_back(i); 
    }
}

int main(){
    int n = 5, x = -10;
    int arr[n] = {10, 2, -2, -20, 10};
    int output =  myfunc(arr, n, x);
    unordered_map<int, vector<int>> mymap;
    mymap[0].push_back(-1);
    cout << mymap[0][0];
    cout << "Output: " << output << endl;
    myfuncdisplay(arr, n, x);
}