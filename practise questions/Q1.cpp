#include <iostream>

using namespace std;

int main()
{
    cout << "\033[2J\033[1;1H";                                        //clear screen
    float x, gross_salary;
    cout<<"Enter Ramesh's basic salary : Rs ";
    cin>>x;
    gross_salary=(x+(20.0/100.0)*x+(40.0/100.0)*x);
    cout<<"\nRamesh's gross salary is Rs "<<gross_salary;

}
