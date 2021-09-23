#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> mymap;
    mymap["abc1"] = 1;
    mymap["abc2"] = 2;
    mymap["abc3"] = 3;
    mymap["abc4"] = 4;
    
    pair<string, int> p("two", 2);
    mymap.insert(p);

    cout << "key: " << mymap["abc1"] << endl;

    //iterator
    map<string, int>::iterator it;
    it = mymap.begin();
    while(it != mymap.end()){
        cout << "key: " << it->first << " value: " << it->second << endl;
        it++;
    }

    //count
    mymap["abc2"] = 8;
    cout << "count of abc2 " << mymap.count("abc2") << endl;
    }