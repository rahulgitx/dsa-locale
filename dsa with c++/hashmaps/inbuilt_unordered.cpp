#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> mymap;
    
    //insertion
    mymap["first"] = 1;
    pair<string, int> p("two", 2);
    mymap.insert(p);

    //access
    cout << "first: " << mymap["first"] << endl;
    cout << "second: " << mymap.at("two") << endl;

    //check presence
    if (mymap.count("third") > 0){
        cout << "Present" << endl;
    }
    else{
        cout << "Not present" <<endl;
    }

    //erase
    mymap.erase("two");
    cout << "two " << mymap.at("two") << endl;
}