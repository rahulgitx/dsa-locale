#include <iostream>
using namespace std;

int main()
{
    string str = "boogiemann";
    int vowelcount = 0;
    int consonantcount = 0;
    for (int i=0; i<str.length(); i++)
    {
        if (str[i] == 'e' || str[i] == 'a' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowelcount++;
        }
        else
        {
            consonantcount++;
        }
    }
    cout << "No of vowels: " << vowelcount << endl;
    cout << "No of consonants: " << consonantcount << endl;
}