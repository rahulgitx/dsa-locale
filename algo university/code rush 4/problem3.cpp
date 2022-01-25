#include <bits/stdc++.h>
using namespace std;

void matrix(int** arr, int n, int k){
    if(k == 0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    if(k > n*n){
        cout << -1;
        return;
    }
    
    int i=0;
    while(k>0){
        if(k == 1){
            int j=i;
            arr[i][j] = 1; k--;
        }
        else{
            for(int j=i; j<n && k>0; j++){
                if(k < 2){
                    break;
                }
                arr[i][j] = 1; k--;
                if(j != i){
                    arr[j][i] = 1; k--;
                }
            }
            i++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }
    // memset(arr, 0, sizeof(arr));
    matrix(arr, n, k);

}