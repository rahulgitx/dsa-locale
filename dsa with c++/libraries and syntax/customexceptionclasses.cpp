#include <iostream>
#include <exception>

using namespace std;

class Overspeed : public exception
{
    int speed;
    public:
        const char* what()
        {
            cout << "This is not your father's car" << endl;
        }
        void setspeed(int speed)
        {
            this-> speed = speed;
        }

};

class car
{
    int speed;
    public:
        car()
        {
            speed=0;
            cout << "your initial speed: " << speed << endl;
        }
        void accelerate()
        {
            for(;;)
            {
                this->speed+=10;
                cout << "speed is: " << speed << endl;
                if (speed > 200)
                {
                    Overspeed s;
                    s.setspeed(speed);
                    throw s;
                }
            }
        }
};

int main()
{
    car rahulscar;
    try
    {
        rahulscar.accelerate();
    }
    catch(Overspeed x)
    {
        cout << "Error: ";
        x.what();
    }
}