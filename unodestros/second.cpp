// time complexity : O(nlogn)
// space complexity: 2n


#include <vector>
#include <iostream>
using namespace std;

void myf(vector<int> arr){
    vector<int> v;
    int flag = 0;
    for (int i=0; i<arr.size(); i++){
        if (arr[i]>=0){
            if (i == (arr.size()-1)){
                v.push_back(arr[i]); //no win
            }
            else if (arr[i+1]<0){
                int temp = (-arr[i+1]);
                if (arr[i]>temp){
                    v.push_back(arr[i]); // win
                }
                else{
                    v.push_back(arr[i+1]); //win
                }
                flag++;
            }
            else{
                v.push_back(arr[i]); //no win
            }
        }
        else{
            if(i == 0){
                v.push_back(arr[i]); //no win
            }
            else if (arr[i-1]<0){
                v.push_back(arr[i]); //no win
            }
        }
    }
    if (flag == 0){
            for (int i = 0; i<v.size(); i++){
                cout << v.at(i) << " ";
            }
        }
        else{
            myf(v);
        }
}

int main(){
    vector<int> potential;
    int n;
    cin>>n;            // 6 -1 2 -3 4 -5 6    //4 -2 1 4 -3   //6 2 -1 3 -4 5 -1
    int temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        potential.push_back(temp);
    }
    myf(potential);

    
}