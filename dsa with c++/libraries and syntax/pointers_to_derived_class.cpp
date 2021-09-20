#include <iostream>

using namespace std;

/*
-when we use a derived object and call a function having same name in base and derived class without using pointers, the derived class'
function is called
- when we do the same thing with pointer the base class' function is called.
- if while using pointers we want it to use the derived class' function then we use the virtual function.
*/



class Base{
    public: 
        int var_base;
        void display()
        {
            cout << "Displaying base class variable: "<< var_base << endl;
        }
};
class Derived : public Base{
    public:
        int var_derived;
        void display()
        {
            cout << "Displaying base class variable from derived class: " << var_base << endl;
            cout << "Displaying derived class variable: " << var_derived << endl;
        }
};

int main()
{
    Base * base_class_pointer;
    Base obj_base;
    Derived obj_derived;
    base_class_pointer = &obj_derived;
    base_class_pointer->var_base=23;
    base_class_pointer->display();

    cout << endl << "**************" << endl;
    
    Derived * derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base=24;
    derived_class_pointer->var_derived=45;
    derived_class_pointer->display();
    
    cout << endl << "***************" << endl;
    
    Derived obj_base2;
    obj_base2.var_base=23;
    obj_base2.var_derived=43;
    obj_base2.display();
}