#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    long int n=0;
    
    for (int i=0; i<s.length(); i++)
    {
        for(int j=0; j<s.length(); j++)
        {
            if (s[i]==s[j])
            {
                 n++;
            }
           
        }
    }
    cout << n;
}