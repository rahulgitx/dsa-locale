#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int main(){
    int x = 321;
    long a = x;
    cout << a << endl;


    int flag = 0;
    long xnew = x;
    cout << "xnew: " << xnew << endl;
    if (xnew<0){
        xnew = -xnew;
        flag = 1;
    }
    cout << "xnew: " << xnew << endl;
    stack<int> s;
    while(xnew!=0){
        s.push(xnew%10);
        xnew = xnew/10;
    }
    cout << "xnew: " << xnew << endl;
    long newno;
    int i=0;
    while(!s.empty()){
        int temp;
        temp = s.top();
        s.pop();
        newno += (temp)*(pow(10,i));
        cout << "newno: " << newno << endl;
        i++;
    }      
    if (flag == 1){
        newno = -newno;
    }
    if(newno<2147483647 && newno>(-2147483648)){
        cout << newno;
    }
    else{
        cout << 0;
    }


}