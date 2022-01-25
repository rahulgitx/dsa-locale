#include <bits/stdc++.h>
using namespace std;

long long awesome(long long n){
    if(n<10){
        return n;
    }
    long long sum = 0;
    while(n>0){
        sum += n%10;
        n = n/10;
    }
    cout << "sum: " << sum << endl;

    return awesome(sum);
}





int main(){
    string n;
    int k;
    cin >> n;
    cin >> k;
    int arr[n.size()];
    long long int firstsum = 0;
    for(int i=0; i<n.size(); i++){
        firstsum  += (n[i] - '0');
    }
    cout << "first firstsum" << firstsum << endl;
    firstsum = firstsum*k;
    cout << "firstsum" << firstsum << endl;
    // for(int i=0; i<n.size(); i++){
    //     cout << arr[i];
    // }
    // cout << endl << "size: " << n.size(); 
    // cout << n;
    cout << awesome(firstsum);
    
}

/*
22 3
*/

/*
7645 3
ans=3
*/

/*
100 5
*/