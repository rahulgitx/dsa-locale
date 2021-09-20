#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
class Calculator : exception
{
    public:
        int power(int a, int b)
        {
            int prod=1;
            if (a<0 || b<0)
            {
                // exception e;
                
                throw runtime_error("n and p should be non-negative");
            }
            else
            {
                for (int i=0; i<b; i++)
                {
                    prod=prod*a;
                }
            }
            return prod;
        }
};


int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}