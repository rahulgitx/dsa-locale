#include <iostream>

using namespace std;

class Base{
    int base_var;
    public:
        Base(int n)
        {
            base_var = n;
            cout << "Base class constructor. Value of base_var: "<< base_var<< endl;
        }
        void display()
        {
            
            cout << "Base class called. Value of base_var : " << endl;
        }
        // Base(){}
};

class Derived : public Base{
    int derived_var;
    public:
        Derived(int a) : Base(a)
        {
            cout << "Derived class called" << endl;
        }
        void display()
        {
            cout << "Derived class called. Running display function" << endl;
        }
};

int main()
{
    // Base objb;
    Derived objd(2);
    // objd.display();
    // objd.Base();
}