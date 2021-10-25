#include <iostream>
#include <vector>

using namespace std;

void myf(int* arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int n = 5;
    myf(arr,n);

    unsigned int y = 2;
    int x = -2;
    if(x>y){
        cout << "x is greater than y";
    }
    else{
        cout << "y is greater than x";
    }
}