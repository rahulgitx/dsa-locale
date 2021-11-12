// a set in c++ is a map without the value pairs. It also uses hashing similar to maps.
// unorderedset stores unique values.
// if you're using set than it will store the elements in sorted way and the complexity of insertion and deletion will be log(n)


#include <unordered_set>
#include <iostream>
using namespace std;

// looping through set
void print(unordered_set<string> s){
    // unordered_set<string>::iterator it = s.begin();          // using iterator
    // for(it = s.begin(); it!=s.end(); it++){
    //     cout << *it << endl;
    // }

    for( auto value : s){              // shorter method 
        cout << value << endl;
    }
}


int main(){
    unordered_set<string> s;
    s.insert("abc");
    s.insert("abc");
    s.insert("rahul");
    s.insert("ads");
    s.insert("sdfalp");

    // checking whether a element is present or not
    cout << endl;
    auto val = s.find("rahul");
    if(val != s.end() ){               // if the value does not exist the end pointer will be handed over to the val variable
        cout << *val << endl;
    }

    // erasing an element
    s.erase(val);         // directly from the iterator which is pointing to that element.
    s.erase("ads");         // and directly writing the element
    cout << endl;
    print(s);

    unordered_set<pair<int, int>> sp;
    sp.insert({1,3});
    sp.insert({2,3});
    sp.insert({1,5});
    sp.insert({4,3});
    for(auto value : sp){
        cout << value.first << " : " <<  value.second << endl;
    }

}