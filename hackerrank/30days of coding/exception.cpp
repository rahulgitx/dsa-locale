#include <iostream>
#include <exception>

using namespace std;

int main()
{
    int a, b, c;
    a=4;
    b=0;
    try
    {
         if (b==0)
            {
                throw b;
            }
    c=a/b;

    }
    catch (int b)
    {
        cout << "invalid value of b: "<< b << endl;
    }
    cout << "After try catch." << endl;
}