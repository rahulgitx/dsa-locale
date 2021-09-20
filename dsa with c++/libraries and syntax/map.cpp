#include <iostream>
#include <map>
 
using namespace std;

void display(map<string, int> m)
{
    map<string, int>::iterator iter;
    for (iter=m.begin(); iter!=m.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << endl;
    }
    cout << endl;
}

int main() 
{
    map<string, int> m1;
    m1["Rahul"]=100;
    m1["Rohan"]=89;
    m1["Sohan"]=69;
    m1["Mohan"]=50;
    // gquiz1.insert(pair<int, int>(1, 40));
    // gquiz1.insert(pair<int, int>(2, 30));
    // gquiz1.insert(pair<int, int>(3, 60));
    // gquiz1.insert(pair<int, int>(4, 20));
    // gquiz1.insert(pair<int, int>(5, 50));
    // gquiz1.insert(pair<int, int>(6, 50));
    // gquiz1.insert(pair<int, int>(7, 10));
    display(m1);
    m1.insert({{"Konohamuru", 34}, {"Akshat", 54}});
    cout << "Inserted" << endl;
    display(m1);
    

}