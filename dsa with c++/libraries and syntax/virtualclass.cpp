#include <iostream>
using namespace std;

/*
when we use virtual class we resolve the ambiguity caused by two joining classes having same variable.
*/

class student{
    protected:
        int rollno;
    public:
        void set_rno(int a)
        {
            rollno = a;
        }
        void print_rno()
        {
            cout << "Your roll no is : " << rollno << endl;
        }

};

class Test : virtual public student{
    protected:
        int maths, physics;
    public:
        void set_marks(float m, float p)
        {
            maths = m;
            physics = p;
        }
        void display_marks()
        {
            cout << "Marks in maths : " << maths << endl;
            cout << "Marks in physics : " << physics << endl;
        }

};

class Sports : virtual public student{
    protected:
        int score;
    public:
        void set_score(int s)
        {
            score = s;
        }
        void display_score()
        {
            cout << "Your PT score is : " << score << endl;
        }
};

class Result : public Test, public Sports{
    private:
        float total;
    public:
        void display_total()
        {
            total = score + maths + physics;
            print_rno();
            display_marks();
            display_score();
            cout << "Overall total by you : " << total << endl;
        }
    
};

int main()
{
    Result rahul;
    rahul.set_rno(3);
    rahul.set_marks(90, 89);
    rahul.set_score(80);
    rahul.display_total();

    // Result * obj[2] = new Result;
    // Result * obj = new Result[2];
    // obj->set_rno(1);
    // (obj+1)->set_rno(2);

    // obj[0]->
    


}