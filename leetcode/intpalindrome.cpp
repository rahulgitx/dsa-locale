/// things to learn : use float or double with pow()
/// float = 3/2 won't give you a decimal no .
/// to get a decimal out of it you'll have to do type conversion: (float)3/2


#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int main(){
        // int reverse = 3;
        // cout << pow(10, 3) << endl;
        // reverse = reverse*(pow(10,3));
        // cout << reverse;
        int x = 1;
        if (x<0){
            cout << "line1" << false;
        }
        else if (x==0){
            cout << "line2"<< true;
        }
        else{
            stack<int> s;
            double reverse=0;
            int val = x;
            double temp = 0;
            while(x!=0){
                temp = x%10;
                // cout << "temp: " << temp << endl;
                s.push(temp);
                // cout << "pushed" << endl;
                x = x/10;
            }
            int i=0;
            temp = 0;
            while(!s.empty()){
                // cout << "s.top: " << s.top() << " power " << pow(10,i) << endl;
                // cout << (s.top())*(pow(10,i)) << endl;
                temp = (s.top())*(pow(10,i));
                reverse = reverse + temp;
                // cout << "temp: " << temp << endl;
                cout << "reverse: " << reverse << endl;
                i++; s.pop();
                
            }
            // cout << "reverse: " << reverse << endl;
            if (val == reverse){
                cout << true;
            }
            else{
                cout << false;
            }
        }

       

        // int x = 5, a = 2;
        // double y = (float)x/2;
        // cout << " y; " << y;


        // faster way 
        /*
        if (x<0){
            return false;
        }
        else if (x==0){
            return true;
        }
        else{
            stack<int> s;
            long reverse=0;
            int val = x;
            // int mult = 1;
            int temp = 0;
            while(x!=0){
                temp = x%10;
                reverse = reverse *10;
                reverse = reverse + temp;
                x = x/10;
            }
            if (val == reverse){
                return true;
            }
            else{
                return false;
            }
        }*/
}