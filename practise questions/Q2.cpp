#include <iostream>

using namespace std;

float conv(float x)
{
    float m=x*1000;
    float c=m*100;
    float f=m*3.28084;
    float i=m*39.3701;
    cout << "Distance in meters : " << m << "m\n";
    cout << "Distance in centimeters : " << c << "cm\n";
    cout << "Distance in feet : " << f << "fts\n";
    cout << "Distance in inches : " << i << "inches"; 
}

int main()
{
    cout << "\033[2J\033[1;1H";
    float distance;
    cout << "Enter the distance between the two cities in kms : ";
    cin>>distance;
    conv(distance);
}