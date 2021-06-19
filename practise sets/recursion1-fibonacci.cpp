#include <iostream>

using namespace std;

int fibonacci(n)
{
    while (n>=0){
        return n+fibonacci(n-1);
    }
    
}

int main(){
    int n;
    cout<<"n = ";
    cin>>n;
    cout<<"\n"<<n<<"//"fibonacci(n);


}