#include <iostream>

using namespace std;

int main()
{
    int a, b, c, n;
    cout << "Enter A : \n";
    cin >> a;
    cout<< "\nEnter B : \n";
    cin >> b;
    cout << "\nEnter C : \n";
    cin >> c;
    if(a>b)
    {
        n=a;
        a=b;
        b=n;
        if(b>c)
        {
            n=b;
            b=c;
            c=n;
            if(a>b)
            {
                n=b;
                b=a;
                a=n;
                cout<<"ascending order: "<<a<<b<<c;
            }
            else
            {
                cout<<"ascending order: "<<a<<b<<c;
            }
        }
        else
        {
            cout<<"ascending order: "<<a<<b<<c;
        }
    }
    else
    {
        if(b>c)
        {
            n=b;
            b=c;
            c=n;
            cout<<"ascending order: "<<a<<b<<c;
        }
        else
        {
             cout<<"ascending order: "<<a<<b<<c;
        }
    }
 

}