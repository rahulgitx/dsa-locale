#include <iostream>
using namespace std;

int main(){
    char c;
    for (int c=0; c<127; c++){
        printf("%c ",c);
    }
    cout << endl;
    for (int c=0; c<127; c++){
        cout << c << " ";
    }
}