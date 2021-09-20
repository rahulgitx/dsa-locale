#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    scanf("%d", &n);
    // vector<string> arr[n]; 
    // for (int i=0; i<n; i++)
    // {
    //     string temp;
    //     cin >> temp;
    //     arr[i].push_back(temp);
    // }
    // for(int i=0; i<n; i++){
    //     for(auto j=arr[i].begin(); j!=arr[i].end(); j++)
    //     {
    //         cout << *j << ' ';
    //     }
    // }
    string arr[n];
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for (int i=0; i<n; i++)
    {
        char c;
        for ( int k=0; arr[i][k]!='\0'; k++){
            c=arr[i][k];
            if (k%2==0)
            {
                cout << arr[i][k];
            }
        }
        cout << " ";
        for ( int k=0; arr[i][k]!='\0'; k++){
            c=arr[i][k];
            if (k%2!=0)
            {
                cout << arr[i][k];
            }
        }
        cout << endl;
    }
    // cout << arr[0][0];
    return 0;
}
