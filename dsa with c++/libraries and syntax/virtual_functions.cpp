#include <iostream>

using namespace std;

/*
They cannot be static
They are accessed by object pointers
Virtual functions can be a friend of another class
A virtual function in the base class might not be used.
If a virtual function is defined in a base class, there is no necessity of redefining it in the derived class

-when we use a derived object and call a function having same name in base and derived class without using pointers, the derived class'
function is called
- when we do the same thing with pointer the base class' function is called.
- if while using pointers of base class pointing to derived class, we want it to use the derived class' function then we use the virtual function.
*/

class CWH{
    protected:
        string title;
        float rating;
    public:
    CWH(string t, float r)
    {
        title = t;
        rating = r;
    }
    virtual void display() { cout << "base class display function " << endl; }   
};

class CWHVideo : public CWH{
    float videolength;
    public:
        CWHVideo(string t, float r, float v) : CWH(t, r)
        {
            videolength = v;
        }
        void display() 
        {
            cout << "Video length for cwhvideo is " << videolength << endl;
            cout << "ratings out of 5 is " << rating << endl;
            cout << "title of the video : " << title << endl;
            cout << endl;
        }
};

class CWHText : public CWH{
    int words;
    public:
        CWHText(string t, float r, int w) : CWH(t,r)
        {
            words=w;
        }
        void display()
        {
            cout << "Title of the video: " << title << endl;
            cout << "Rating out of 5 : " << rating << endl;
            cout << "No of words in the content: " << words << endl;
            cout << endl;
        }
};


int main()
{
    string title;
    float rating, vlen;
    int words;

    // for video
    title = "Django tutorial";
    vlen = 4.56;
    rating = 4.2;
    CWHVideo objvid(title, rating,  vlen);

    // for text
    title = "Django tutorial text";
    words = 555;
    rating = 4.5;
    CWHText objtext(title, rating, words);

    objvid.display();
    objtext.display();

    cout << "***********using pointers************" << endl << endl;

    CWH * ptr[2];
    ptr[0] = &objvid;
    ptr[1] = &objtext;

    ptr[0]->display();
    ptr[1]->display();

}