#include <iostream>
#include <stack>
using namespace std;

template<class T>
class myqueue{
    stack<T> first;
    stack<T> second;
    public:
        void push(T a){
            first.push(a);
        }
        void pop(){
            if(second.empty()){
                while(!first.empty()){
                    second.push(first.top());
                    first.pop();
                }
                second.pop();
            }
            else{
                second.pop();
            }
        }
        T front(){
            if(second.empty()){
                while(!first.empty()){
                    second.push(first.top());
                    first.pop();
                }
                return second.top();
            }
            else{
                return second.top();
            }
        }
};

int main(){
    myqueue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout << q1.front() << " ";
    q1.pop();
    cout << q1.front() << " ";
    q1.pop();
    cout << q1.front() << " ";
    q1.pop();

}