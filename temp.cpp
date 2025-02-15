#include <bits/stdc++.h>
using namespace std;

class Robot{
    public:
        int health;
        int position;
        char direction;
        int initialIndex;
        bool alive = true;
        Robot(int health, int pos, char dir, int ind){
            this->health = health;
            this->position = pos;
            this->direction = dir;
            this->initialIndex = ind;
        }
};
int main(){
  stack<int> st;
  st = {1};
}

/*
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
*/