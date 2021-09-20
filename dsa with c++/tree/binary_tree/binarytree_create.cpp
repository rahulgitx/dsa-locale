#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int a)
    {
        this->data = a;
        this->left = NULL;
        this->right = NULL;
    }
};

// node* create(int a)
// {

// }

void main()
{
    // node root(1);
    node* root = new node(1);
    node* child1 = new node(2);
    node* child2 = new node(3); 
    node* child3 = new node(4); 
    node* child4 = new node(5); 
    node* child5 = new node(6); 
    node* child6 = new node(7); 
    node* child7 = new node(8); 
    
    root->left=child1;
    root->right=child2;
    child1->left=child3;
    child1->right=child4;
    child2->left=child5;
    child2->right=child6;
    
// the above method will create separate pointers pointing to a memory having a struct object. 
// so the parents child left pointer will be point to the same area that the child node pointer will be pointing to 
// so the same location will be pointed to by two pointers

// to remove this pointer we can do this in this way

    node* roott = new node(1);
    roott->left = new node(2);
    roott->right = new node(3);
    root->left->left = new node(4);
    roott->left->right = new node(5);
    roott->right->left = new node(6);
    roott->right->left = new node(7);

}

