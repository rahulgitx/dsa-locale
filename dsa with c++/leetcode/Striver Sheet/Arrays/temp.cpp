#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 100000;
    cout << INT_MAX << " " << LONG_MAX << " " << LONG_LONG_MAX << endl;
    long long sum = n;
    sum *= (n+1);
    sum /=2;
    // sum = (n*(n+1))/2;
    cout << sum;
}
