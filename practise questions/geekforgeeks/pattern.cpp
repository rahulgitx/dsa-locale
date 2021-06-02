//Print the pattern | Set-1 
#include <iostream>

using namespace std;

int printPat(int n)
{
//Your code here
    for (int i=n; i>0; i--)
    {
        for (int j=n; j>0; j--)
        {
            for (int k=i; k>0; k--)
            {
                cout<<j<<" ";
            }
        }
        
        cout << "$ ";
        
    }
}

int main()
{
    int N;
    cout<< "Enter the number N : \n";
    cin >> N;
    printPat(N);
}