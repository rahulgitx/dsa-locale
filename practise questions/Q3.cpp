#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cout << "Enter the number of stars in the last line (equal to the no of lines to be printed) : \n";
    cin >> n;
    m=(n+n-1)/2+1;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cout<<" ";
        }
        for (int k=1; k<=i; k++)
        {
            cout << "* ";
        }
        m=m-1;
        cout << "\n";
    } 
}