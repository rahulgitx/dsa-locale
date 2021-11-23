#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// void myf(int* arr, int n){
//     for(int i=0; i<n; i++){
//         cout << arr[i] << " ";
//     }
// }

// int ret(int num){
//     while(num>0){
//         return (num+ret(num-2));
//     }
//     return num;
// }

// void func(void);
// static int count = 5;

int minkit(vector<int> arr, int n){
    int totalsum = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        totalsum += arr[i];
    }
    // cout << totalsum << endl;
    sort(arr.begin(), arr.end(), greater<int>());
    int minkits = 0;
    for(int i=0; i<n; i++){
        // cout << arr[i] << endl;
        minkits = minkits+arr[i];
        count++;
        // cout << "minkits: " << minkits << count << endl;

        if((totalsum >= 0) && minkits > (totalsum/2)){
            // cout << "breaking: " << minkits+arr[i] << endl;
            break;
        }

        if((totalsum < 0) && minkits >= (totalsum/2)){
            // cout << "breaking: " << minkits+arr[i] << endl;
            break;
        }
    
    }
    // cout << minkits;
    return count;


}

int main(){
 
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << minkit(arr, n);
    

        // unsigned int y = 2;
    // int x = -2;
    // if(x>y){
    //     cout << "x is greater than y";
    // }
    // else{
    //     cout << "y is greater than x";
    // }
    
    // while(count--){
    //     func();
    // }    
    // return 0;
}

/*
3 
4 3 2
*/
/*
5
4 2 1 5 6
*/

/*
2
-1 -2
*/

// void func(void){
//     static int i=5; i++;
//     cout << "1 is " << i << " and count is " << count << endl;
// }