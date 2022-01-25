#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &x, vector<int> &y, int m, int n){
    int arr[n+m];    
    int i=0, j=0, k=0;
    while(i<m || j<n){
        cout << "inside while loop" << endl;
        if(i<m && j<n){
            cout << "first else if" << endl;
            cout << "x: " << x[i] << " y: " << y[j] << endl;
            if(x[i] <= y[j]){
                arr[k] = x[i];
                cout << "arr[k]: " << arr[k] << endl;
                k++; i++;
            }
            else{
                arr[k] = y[j];
                cout << "arr[k: " << arr[k] << endl;
                k++; j++;

            }
            // cout << "inside if: " << endl;
        }
        else if(j >= n){
            cout << "second elf if " << endl;
            for(int it=i+1; it<m; it++){
                arr[k] = x[it];
                k++;
            }
            i=m;
        }
        else if(i>=m){
            cout << "third else if" << endl;
            for(int it=j; it<n; it++){
                arr[k] = y[it];
                k++;
            }
            j=n;
        }
        cout << "i: " << i << " j: " << j << " k: " << k << endl << endl;
    }

    for(int i=0; i<m+n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    vector<int> x, y;
    int n, m;
    cin >> m >> n;
    int temp;
    for(int i=0; i<n+m; i++){
        cin >> temp;
        x.push_back(temp);
    }
    for(int j=0; j<n; j++){
        cin >> temp;
        y.push_back(temp);
    }
    cout << "arr1: " ;
    for(int i=0; i<n+m; i++){
        cout << x[i] << " ";
    }
    cout << endl << " arr2: ";
    for(int i=0; i<n; i++){
        cout << y[i] << " ";
    }
    cout << endl;
    merge(x,y,m,n);
}

/*
3 3 
1 2 3 0 0 0
2 5 6
*/

/*
0 1
0
1
*/

/*
1 0
1
*/