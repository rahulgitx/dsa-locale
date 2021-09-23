#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    unordered_map<string, int> mymap;
    mymap["key1"] = 1;
    mymap["key2"] = 2;
    mymap["key3"] = 3;
    mymap["key4"] = 4;
    mymap["key5"] = 5;
    mymap["key6"] = 6;

    unordered_map<string, int>::iterator it = mymap.begin();
    while(it != mymap.end()){
        cout << "key: " << it->first << " value: " << it->second << endl;
        it++;
    }

    //finding
    it = mymap.find("key2");
    cout << " found : " << it->first << " : " << it->second << endl;

    //erase
    // mymap.erase(it, it+2);
    while(it != mymap.end()){
        cout << "key: " << it->first << " value: " << it->second << endl;
        it++;
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator iter = v.begin();
    while(iter != v.end()){
        cout << "value: " << *iter << endl;
        iter++;
    }

}