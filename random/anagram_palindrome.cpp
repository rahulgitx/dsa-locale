// CPP program to illustrate
// find
// CPP program to illustrate
// find
// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    string s = "cdcdcdcdeeeef";

	vector<string> vec ;

	vector<string>::iterator it;
    vector<int> occurrence;
	
    for (int i = 0; i<s.length(); i++)
    {
        char temp=s[i];
        string t(1, temp);


        it = find(vec.begin(), vec.end(), t);
        if (it!=vec.end())
        {
            cout << "element found in checklist, checking for next " << endl;
            
        }   
        else
        {
            cout << "not found in checklist " << endl;
            int count=0;
            for (int j=i+1; j<s.length(); j++)
            {
                if (s[i]==s[j])
                {
                    cout << " s[i] " << s[i] << " s[j] " << s[j] << endl;
                    count+=1;
                }
            }
            occurrence.push_back(count+1);
            vec.push_back(t);
        }
 
    }
    
    
    cout << endl;
    for (int i=0; i<vec.size(); i++)
    {
        cout<< "checklist of vec: " << vec[i] << " " << endl;
    }

    int oddcount=0;
    for (int i=0; i<occurrence.size(); i++)
    {
        cout << "occurence: " << occurrence[i] << " ";
        if (occurrence[i]%2==1)
        {
            oddcount+=1;
        }
    }
    cout << endl;
    if (oddcount>1)
    {
        cout << "not a palindrom" << endl;
    }
    else
    {
        cout << "palindrom" << endl;
    }

		
	cout << "\n";
	
	
	string ser = "a";

	

		
    cout << "my output";
	return 0;
}
