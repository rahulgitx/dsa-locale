#include <iostream>
using namespace std;

int check(int n){
    int temp = n&(n-1);
    cout << temp << endl;
    return (n && !(n&(n-1)));
}

int main()
{
    int n = -8;
    int output = check(n);
    if (output == 1){
        cout << "Power of two" << endl;
    }
    else{
        cout << "Not a power of two" << endl;
    }
}