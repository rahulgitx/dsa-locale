#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string str = "tag1.tag2.tag3~final";
    // cout << str;
    stringstream s(str);
    string word;
    string im;
    // while(s >> word)
    // {
    //     cout << word;
    // }
    cout << endl;
    while(getline(s,im,'~'))
    {
        cout << im << endl;
    }

    // cout << word;

}