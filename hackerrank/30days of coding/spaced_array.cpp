#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, a;
    
    // scanf("%d", &n);
    cin >> n;
    short int arr[n];
    a=n;
    // printf(" %d ", n); 
    for (int i=0; i<n; i++){
        //scanf("%d", &arr[i]);
        cin >> arr[i];
        // printf(" %d ", n); 
    }
    // printf("     %d", a); 
    // cout << a ;
    for (int k=a-1; k>=0; k--){
        // printf("%d ", arr[k]);
        cout << arr[k] << " ";
    }
    return 0;
}