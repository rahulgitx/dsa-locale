#include <iostream>
using namespace std;


void subarr(int arr[], int n, int x){
    int i=0, j=0, sum=0, count=0;
    if (x > 0)
    while( i <= n){
        // cout << "i: " << i << " j: " << j << endl;
        // cout << "inside while loop" << endl;
        for (int k=i; k <= j; k++){
            sum += arr[k];
            // cout << "sum in adding: " << sum << " with j: " << j;
            // cout << "inside for";
        }
        // cout << "sum " << sum << " i: " <<i << " j: " << j << endl;
        if (sum == x){
            // cout << " sum == x" << endl;
            count++;
            // cout << "count increased" << endl;
            sum=0;
            j++; 
            // cout << "increasing j: " << j <<endl;
            // continue;
        }
        else if (sum < x){
            // cout << "sum < x" << endl;
            if (j == n){
                // cout << "trying to break" << endl;
                // cout << "count: " << count;
                return;
            }
            else{
                j++; 
                sum=0;
            }
        }
        else {
            // cout << "sum > x" << endl;
            if (i==j){
                i++; j++;
                sum=0;
            }
            if (i < j){
                i++;
                sum=0;
            }
        }
        // cout << "moving to next while " << endl;
    }
    cout << "count: " << count;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){    // 7 1 2 3 4 0 0 5 9
        cin >> arr[i];
    } 
    for (int i=0; i<n; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
    int x;
    cin >> x;
    subarr(arr, n, x);
    
}