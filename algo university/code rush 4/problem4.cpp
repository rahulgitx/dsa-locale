#include <bits/stdc++.h>
using namespace std;

int search(long long int* difficulty, int i, int k, int n){
    int first = i;
    int last = n-1;
    int ans = difficulty[i]+k;
    int mid;
    while(first <= last){
        mid = first + (last-first)/2;
        // cout << first << " : " << mid << " : " << last << endl;
        if(first == last){
            return mid;
        }
        if(difficulty[mid] < ans){
            first = mid+1;
        }
        else if(difficulty[mid]  > ans){
            last = mid;
        }
        else{
            if(last-first <= 1){
                return mid;
            }
            else{
                last = mid;
            }
        }
    }
    return 0;
}

unsigned long long int nopairs(int n, int k){
    //initialization
    long long int* fibo = new long long int[n];
    long long int* difficulty = new long long int[n];
    // for(int i=0; i<n; i++){
    //     fibo[i] = -1;
    //     difficulty[i] = -1;
    // }
    fibo[0] = 1;
    fibo[1] = 1;
    difficulty[0] = 1;
    difficulty[1] = 1;

    int mod = 10;
    for(int i=2; i<n; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2])%mod;
        difficulty[i] = difficulty[i-1] + fibo[i]; 
    }

    // cout << difficulty[n-1] << endl;
    // cout << "fibo: ";
    // for(int i=0; i<n; i++){
    //     cout << fibo[i] << " ";
    // }
    // cout << endl << "difficulty: ";
    // for(int i=0; i<100; i++){
    //     cout << difficulty[i] << " ";
    // }
    // cout << endl;
    // cout << " done " << endl;

    unsigned long long int sum = 0;
    for(int i=0;  difficulty[i]+k <= difficulty[n-1]; i++){
        // cout << "i: " << i << endl;
        int back = search(difficulty, i, k, n);
        // cout << "ans back: " << back << endl;
        sum += n-search(difficulty, i, k, n);
        // cout << endl;
    }

    return sum;

}


int main(){
    int n, k;
    cin >> n >> k;
    cout << n << " " << k << endl;
    cout << nopairs(n, k);
}

/*
10000000 1000
*/