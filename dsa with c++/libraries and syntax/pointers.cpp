#include <iostream>
using namespace std;

int* func(int *x){
    *x = *x + 1;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main(){
// int *x = new int;
// *x = 5;
// int* output = func(x);
// cout << *output << endl;
// int address = output;
// cout << endl << address;

int* node = new int;
int x = 5;
node = &x;
int* node2 = node;
*node++;
// cout << *node2;

TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);

TreeNode* temp1;
temp1 = new TreeNode;
TreeNode* temp2 = temp1;
temp1->val = root->val;
temp1->left = new TreeNode(4);
temp1=temp1->left;
temp1->val = 88;
cout << temp2->left->val;
cout << endl << root->left->val;
}