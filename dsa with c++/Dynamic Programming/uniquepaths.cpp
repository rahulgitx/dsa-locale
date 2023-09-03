/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.*/

#include <bits/stdc++.h>
using namespace std;

long long fact(int x){
    long long fact = 1;
    for(int i=1; i<=x; i++){
        fact = fact*i;
    }
    return fact;
}


int uniquepaths(int m, int n){
    if(m <= 1 || n <= 1){
        return 1;
    }
    int x = m-1;
    int y = n-1;
    int sum = x+y;
    int greater = max(x,y);
    int smaller = min(x,y);
    long long den = sum;
    sum = sum-1;
    while(sum > greater){
        den = den*sum;
        sum = sum-1;
    }
    cout << "den: " << den << endl;

    int num = fact(smaller);
    cout << "num: " << num << endl;

    return den/num;
}

int main(){
    int m, n;
    cin >> m >> n;
    // cout << fact(n);
    cout << "ans: " << uniquepaths(m, n);
}