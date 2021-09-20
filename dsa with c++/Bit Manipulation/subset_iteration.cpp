#include <iostream>
#include <math.h>
using namespace std;

int swittch(int n){
    if (n==1){
        return 0;
    }
    else return 1;
}

// time complexity for function = O(n * 2^n)
void iterate(int arr[], int n){
    int place[n];
    place[0]=0;
    place[1]=0;
    place[2]=0;
    place[3]=0;
    // cout << "pow" << pow(2,n) << endl;
    for (int i=1; i <= pow(2,n); i++){
        for (int j =0; j < n; j++){
            int power = pow(2,j);
            if (i % (power) == 0){
                place[j]=swittch(place[j]);
                // cout << "switched " << place[j];
            }
        }
        // cout << "i: " << i << " ";
        // cout << place[3];
        // cout << place[2];
        // cout << place[1];
        // cout << place[0];

        cout << " {" ;
        if (place[0] == 1){
            cout << arr[0];
        }
         if (place[1] == 1){
            cout << arr[1];
        }
         if (place[2] == 1){
            cout << arr[2];
        }
         if (place[3] == 1){
            cout << arr[3];
        }
        cout << "}";
        cout << endl;



    }

}

int main(){
    int n = 4;
    int arr[n] = {1, 2, 3, 4};
    iterate(arr, n);
}