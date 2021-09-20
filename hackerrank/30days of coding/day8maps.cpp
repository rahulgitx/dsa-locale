#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map<string, int> m;
    string name;
    int n, pno;
    scanf("%d", &n);
    // scanf("%s", &name);
    
    for (int i=0; i<n; i++)
    {
        cin >> name >> pno;        
        m.insert(pair<string, int>(name, pno));
    }
    map<string, int>::iterator iter;
    map<string, int>::iterator match;
    
    while(true)
    {
        string q="NO_NAME";
        cin >> q;
        if(q!="NO_NAME")
        {
            match = m.find(q);
            if (match==m.end())
            {
                cout << "Not found" << endl;
            }
            else
            {
                cout << (*match).first << "=" << (*match).second << endl;
            }
        }
        else
        {
            break;
        }
    }
    
    return 0;
}