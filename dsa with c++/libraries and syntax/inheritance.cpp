#include <iostream>

using namespace std;

class Employee{
    public:
        int id;
        float salary;
        Employee(int inpid)
        {
            id=inpid;
            salary=34.0;
        }
        void empoutput()
        {
            cout << "id: " << id << endl;
            cout << "salary: " << salary << endl;
        }
        Employee(){}             // no idea why we do it
};

class Programmer : public Employee{
    public: 
        int languagecode;
        Programmer(int inpid)
        {
            id = inpid;
        }
        void inputlc(int i)
        {
            languagecode = i;
        }
        void output()
        {
            cout << "id: " << id << endl;
            cout << "languagecode: " << languagecode << endl;
        }
};

int main()
{
    Employee e1(111);
    e1.empoutput();
    Programmer p1(222);
    p1.inputlc(34);
    p1.output();
}