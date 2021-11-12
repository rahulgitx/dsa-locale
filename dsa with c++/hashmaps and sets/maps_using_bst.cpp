#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
        string key;
        int value;
        node* left;
        node* right;
        node(string k, int v){
            this->key = k;
            this->value = v;
            left = NULL;
            right = NULL;

        }

};

void insert(node* root, string key, int value){
    node* prev = NULL;
    while(root!=NULL){
        if (root->key == key){
            cout << "Entry with this key already exists." << endl;
            return ;
        }
        if (root->key < key){
            prev = root;
            root = root->right;
        }
        else if (root->key > key){
            prev = root;
            root = root->left;
        }
    }
    node* temp = new node(key, value);
    if (key < prev->key){
        prev->left = temp;
        cout << "inserted on left" << endl;
    }
    else if (key > prev->key){
        prev->right = temp;
        cout << "inserted on right" << endl;
    }
    else{
        cout << "Can't insert value. Already exists." << endl;
    }
}

void display(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* frontn = q.front();
        q.pop();
        q.push(frontn->left);
        q.push(frontn->right);
   
        cout << frontn->key << ": " << frontn->value << ", left child: ";
        if(frontn->left == NULL){
            cout << " NULL ";
        }
        else{
            cout << frontn->left->key;
        } 
        cout  << " , right child: ";
        if(frontn->right == NULL){
            cout << " NULL" << endl;
        }
        else{
            cout << frontn->right->key << endl;
        } 
        
    
    }
}

int main(){
    node* root = new node("k", 1);
    insert(root, "d", 2);
    insert(root, "h", 3);
    insert(root, "b", 3);
    insert(root, "q", 3);
    insert(root, "m", 3);
    insert(root, "t", 3);
    // cout << root->right->key << endl;
    display(root);
    // insert(root)
    // node* output = NULL;
    // cout << output->key;
}