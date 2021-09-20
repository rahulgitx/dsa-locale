#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int a = 10 , b = 0;
    try
    {
        if (b==0)
        {
            throw  runtime_error("error no 234");
        }
        int c = a/b;
        cout << "value of c: " << c << endl;
    }
    catch(runtime_error x)
    {
        cout << "error! value of b is : " << x.what();
    }
}