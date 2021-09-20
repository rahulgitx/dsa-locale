#include <stdexcept>
#include <iostream>

using namespace std;

void func() throw(int, char, runtime_error)
{
    throw runtime_error("hello there");
}

int main()
{
    try
    {
        func();
    }
    catch(int a)
    {
        cout << "int type exception: " << a;
    }
    catch(char a)
    {
        cout << "char type exception: " << a;
    }
    catch(...)
    {
        cout <<"default type exception";
    }
}