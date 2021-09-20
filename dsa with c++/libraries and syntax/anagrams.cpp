#include <iostream>
using namespace std;

int main()
{
    string str1 = "listen", str2 = "silent";
    if (str1.length() != str2.length())
    {
        cout << "Not anagram";
    }
    else
    {
        string str1sorted = sort(str1.begin(), str1.end());
        string str2sorted = sort(str2.begin(), str2.end());
        
    }
}