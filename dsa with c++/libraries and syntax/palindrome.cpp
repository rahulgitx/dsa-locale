#include <iostream>

using namespace std;

int main()
{
    string strorg = "abracadabra";
    string strcomp = strorg;
    // reversing the string
    int temp, n = strcomp.length()-1;
    for (int i=0; i<(strcomp.length()/2); i++)
    {
        temp = strcomp[i];
        strcomp[i] = strcomp[n-i];
        strcomp[n-i] = temp;
    }
    if (strcomp == strorg)
    {
        cout << "Palindrome";
    }
    else 
    {
        cout << "Not a palindrome";
    }

}