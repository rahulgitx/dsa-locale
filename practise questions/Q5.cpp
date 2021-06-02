#include <iostream>

using namespace std;

int main()
{
    int n, flag=1;
    cout << "Enter the size of swastika : (greater than 4)";
    cin >> n;
    if (n%2!=0)
    {
        for(int i=1; i<=n; i++)
        {
            if (i==1)               // for first line
            {
                cout << "*";
                for(int j=0; j<n-2; j++)
                {
                    cout << " " ;
                }
                for(int j=0; j<((n+1)/2); j++)
                {
                    cout<< "* ";
                }
                cout<< "\n";
            }                
            if(i>1 && i<((n+1)/2))                       //before middle
            {
                cout<<"*";
                for (int j=0; j<(n-2); j++)
                {
                    cout << " ";
                }
                cout << "*\n";
            }
            if (i==((n+1)/2))                      //middle line
            {
                for (int j=0; j<n; j++)
                {
                    cout<< "* ";
                }
                cout << "\n";
            }
            if ((i>((n+1)/2)) && (i<n))                //after middle
            {
                for (int j=0; j<(n-1); j++)
                {
                    cout << " ";
                }
                cout<<"*";
                for (int j=0; j<(n-2); j++)
                {
                    cout << " ";
                }
                cout << "*\n";
                flag=flag+1;  
            }
            if (i==n)
        {
            for(int j=0; j<((n+1)/2); j++)
            {
                cout<< "* ";
            }
            for(int j=0; j<n-3; j++)                   // one less because last loops * has a space
            {
                cout << " " ;
            }
            cout<<"*\n\n\n";
        }
        }
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if (i==1)               // for first line
            {
                cout << "*";
                for(int j=0; j<n-2; j++)
                {
                    cout << " " ;
                }
                for(int j=0; j<((n+1)/2); j++)
                {
                    cout<< "* ";
                }
                cout<< "\n";
            }                
            if(i>1 && i<((n+1)/2))                       //before middle
            {
                cout<<"*";
                for (int j=0; j<(n-2); j++)
                {
                    cout << " ";
                }
                cout << "*\n";
            }
            if (i==((n+1)/2))                      //middle line
            {
                for (int j=0; j<n; j++)
                {
                    cout<< "* ";
                }
                cout << "\n";
            }
            if ((i>((n+1)/2)) && (i<n))                //after middle
            {
                for (int j=0; j<(n-1); j++)
                {
                    cout << " ";
                }
                cout<<"*";
                for (int j=0; j<(n-2); j++)
                {
                    cout << " ";
                }
                cout << "*\n";
                flag=flag+1;  
            }
            if (i==n)
        {
            for(int j=0; j<((n+1)/2); j++)
            {
                cout<< "* ";
            }
            for(int j=0; j<n-2; j++)                   // one less because last loops * has a space
            {
                cout << " " ;
            }
            cout<<"*\n\n\n";
        }
        }
    }
}