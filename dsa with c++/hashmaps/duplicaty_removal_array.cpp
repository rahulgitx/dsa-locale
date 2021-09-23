#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void duplicacy(int arr[], int n){
    unordered_map<int, string> checklist;
    vector<int> newarr;
    for (int i=0; i<9; i++){
        if ( checklist.count(arr[i]) == 0){
            checklist[arr[i]] = "present";
            newarr.push_back(arr[i]);
        }
    }  
    for (int i=0; i<newarr.size(); i++){
        cout << newarr.at(i) << " ";
    }
    cout << endl;
}

int main(){
    int n = 9;
    int arr[n] = { 1, 2, 3, 2, 1, 5, 4, 1, 3};
    duplicacy(arr, n);    

    

}