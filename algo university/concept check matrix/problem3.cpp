#include <bits/stdc++.h>
using namespace std;

void traverse(vector<vector<int>> arr, int a, int b, int p, int q){
    int i=a, j=b;
    int ilast = 0, jlast = 0, dir = 1;
    if(arr[i][j] != 0){
        cout << i << " " << j << " " << arr[i][j] << " " << dir << endl;
    }
    // cout << "dir? " << dir << endl;
    while(i>=0 && i<p && j>=0 && j<q){
        if(dir == 1){
            int k;
            for(k=i+1; k<= i+1+(ilast); k++){
                if(k>p-1){
                    return;
                }
                if(arr[k][j] != 0){
                    cout << k << " " << j << " " << arr[k][j] << " " << dir << endl; 
                }
                // else{
                //     cout << k << " " << j << " " << dir << endl ;
                // }
            }
            i = k-1; ilast++;
        }
        else if(dir == 2){
            int k;
            for(k =j+1; k<= j+1+(jlast); k++){
                if(k>q-1){
                    return;
                }
                if(arr[i][k] != 0){
                    cout << i << " " << k << " " << arr[i][k] << " " << dir << endl; 
                }
                // else{
                //     cout << k << " " << j << " " << dir << endl ;
                // }
            }
            j = k-1; jlast++;
        }
        else if(dir == 3){
            int k;
            for(k=i-1; k>= i-1-(ilast); k--){
                if(k<0){
                    return;
                }
                if(arr[k][j] != 0){ 
                    cout << k << " " << j << " " << arr[k][j] << " " << dir << endl;
                }
                // else{
                //     cout << k << " " << j << " " << dir << endl ;
                // }
            }
            i = k+1; ilast++;
        }
        else{
            int k;
            for(k=j-1; k>=j-1-(jlast); k--){
                if(k<0){
                    return;
                }
                if(arr[i][k] != 0){
                    cout << i << " " << k << " " << arr[i][k] << " " << dir << endl;
                }
                // else{
                //     cout << k << " " << j << " " << dir << endl ;
                // }
            }
            j = k+1; jlast++;
        }
        dir++;
        if(dir > 4){
            dir = 1;
        }
        // cout << "i: " << i << " j: " << j << " dir: " << dir << endl;
    }
    // cout << "done";
}

int main(){
    int p, q, n;
    cin >> p >> q >> n;

    vector<vector<int>> arr(p, vector<int> (q, 0));
    int x, y, val;
    for(int i=0; i<n; i++){
        cin >> x >> y >> val;
        arr[x][y] = val;
    }

    cout << "array: ";
    for(int i=0; i<p; i++){
        for(int j=0; j<q; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int a, b;
    cin >> a >> b;
    if(n == 0){
        cout << -1;
        return 0;
    }
    traverse(arr, a, b, p, q);
    // return 0;
}

/*
3 3 9
0 0 1
0 1 2
0 2 3
1 0 4
1 1 5
1 2 6
2 0 7
2 1 8
2 2 9
1 1
*/

/*
1 1 1
0 0 1
0 0
*/
/*
1 5 5
0 0 9
0 1 1
0 2 2
0 3 3
0 4 4
0 0
*/
/*
5 1 5
0 0 5
1 0 1
2 0 2
3 0 3
4 0 4
0 0
*/