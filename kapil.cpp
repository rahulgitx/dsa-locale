#include <bits/stdc++.h>
using namespace std;


void func(int a){
        cout << a;
        func(a);
        return;
}

int main(){
        func(1);
}



/*
4 2
1 5 8 10
*/

/*
6 9
10 11 12 13 14 15
*/

/*
3 
4 5 6
*/