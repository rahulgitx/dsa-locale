#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

//for counting  --> O(n^2)
int countofno(int arr[], int n){
    unordered_map<int, int> mymap;
    unordered_map<int, int>::iterator it;
    for (int i=0, j=1; i<n-1, j<n; i++, j++){
        // int j = i+1;
        it = mymap.begin();
        if (arr[i]%2 == 0){
            mymap[arr[i]] = 1;
        }
        if (arr[j]%2 != 0){
            while(it != mymap.end()){
                it->second += 1;
                it++;
            }
        }
        // it = mymap.begin();
    }
    it = mymap.begin();
    int total = 0;
    while(it != mymap.end()){
        total += it->second;
        it++;
    }
    return total;
}

int myf(int arr[], int n){
    int evencount = 0;
    int paircount = 0;
    for (int i=0; i<n; i++){
        int j=i+1;
        if (arr[i]%2 == 0){
            evencount++;
        }
        if (arr[j]%2 != 0){
            paircount = evencount + paircount;
        }
    }
    return paircount;
}

//for displaying the pairs
void displaypairs(int arr[], int n){
    vector<int> v;
    vector<int>::iterator it;
    for (int i=0; i<n; i++){
        int j=i+1;
        it = v.begin();
        if(arr[i]%2 == 0){
            v.push_back(arr[i]);
        }
        if (arr[j]%2 != 0){
            if(!v.empty()){
                for (int k = 0; k < v.size(); k++){
                    cout << "{" <<  v[k]  << "," <<arr[j]<< "}" << endl;
                }
            }
        }
    }
}

int main(){
    int n = 9;
    int arr[9] = {2,3,4,5,6,7,8,9,10};
    int output = countofno(arr, n);
    // cout << output << endl;
    // displaypairs(arr, n);
    output = myf(arr, n);
    cout << output;
    
}