#include <iostream>
using namespace std;


// dynamic programming
long long int fibdp(long long int n){
    long long int *arr = new long long int[n];
    arr[0] = 0;
    arr[1] = 1;
    if(n <= 1){
        return n;
    }
    for(int i=2; i<=n; i++){
        // arr[i] = arr[i-1] + arr[i-2];
        arr[i] = ( arr[i-1]%1000000007 + arr[i-2]%1000000007 )%100000007;
    }
    return arr[n];
}


// memoization
// long long int fib(long long int* arr, long long int n){
    
//     if(arr[n] != -1){
//         return arr[n];
//     }
//     else{
//         // arr[n] = fib(arr, n-1) + fib(arr, n-2);
//         arr[n] = ( (fib(arr, n-1))%1000000007 + (fib(arr, n-2))%1000000007 )%1000000007;
//     }
//     return arr[n];
    
// }
// long long int nthFibonacci(long long int n){           
//     // code here
//     long long int *arr = new long long int[n+1];
//     for(int i=0; i<n+1; i++){
//         arr[i] = -1;
//     }
    
//     arr[0] = 0;
//     arr[1] = 1;
    
//     return  fib(arr, n);
    
// }

int main(){
    long long int n;
    cin >> n;
    // cout << nthFibonacci(n);
    cout << fibdp(n);
}