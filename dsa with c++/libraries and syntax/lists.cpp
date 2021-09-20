#include <iostream>
#include <list>

using namespace std;

void display(list<int> lst)
{
    list<int>::iterator iter;
    for (iter=lst.begin(); iter!=lst.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l1;
    l1.push_back(34);
    l1.push_back(33);
    l1.push_back(54);
    l1.push_back(33);
    l1.push_back(23);
    l1.push_back(51);
    l1.push_back(56);
    l1.push_back(13);
    l1.push_back(14);
    display(l1);
    l1.pop_back();
    display(l1);
    l1.remove(54);                    // removing element 54
    //display(l1);
    l1.sort();                          // sorting our list
    display(l1);
    list<int>::iterator iter = l1.begin();
    ++iter;
    l1.insert(iter, 45); 
    cout << "inserted " << endl;                //inserting at second position
    display(l1);
    iter--;
    l1.erase(iter);
    // cout << *iter;
    
    cout << "erased " << endl;
    display(l1);
}