#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {
        throw "what is this bullshit";
    }
    catch(char const* x)
    {
        cout << x;
    }
}