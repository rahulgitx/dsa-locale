#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class T>
class treenode{
    public:
        T data;
        vector< treenode<T>* > children;
        treenode(T data)
        {
            this->data = data;
        }
        ~treenode()
        {
            for (int i=0; i < this->children.size(); i++)
            {
                delete children[i];
                cout << this->data << " is deleted" << endl;
            }
        }
};


treenode<int>* insertTree()
{
    int data;
    cout << "Enter the data for root node: ";
    cin >> data;
    treenode<int>* root = new treenode<int>(data);
    queue< treenode<int>* > q;
    q.push(root);
    while(!q.empty())
    {
        treenode<int>* front = q.front();
        q.pop();
        cout << "How many children are there of " << front->data << " node?" << endl;
        int n;
        cin >>n;
        for (int i=0; i<n; i++)
        {
            cout << "Enter the data for child: " << i+1 << endl;
            cin >> data;
            treenode<int>* child = new treenode<int>(data);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void printTree(treenode<int>* root)
{
    if (root == NULL)
    {
        cout << "NULL" << endl;
    }
    cout << root->data << " : ";
    for (int i=0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data <<", ";
    }
    cout << endl;
    for (int i=0; i<root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int countleafnodes(treenode<int>* root)
{
    static int count =0;
    if (root == NULL)
    {
        count++;
        cout << "NULL " ;
    }
    else if ( root->children.empty())
    {
        cout << root->data << " ";
        count++;
    }
    else
    {
        for(int i=0; i < root->children.size(); i++)
        {
            countleafnodes(root->children[i]);
        }
    }
    cout << endl;
    return count;
}

void levelordertraversal(treenode<int>* root)
{
    if (root == NULL)
    {
        cout << "NULL";
        return;
    }
    else
    {
        queue< treenode<int>* > q;
        q.push(root);
        while(!q.empty())
        {
            treenode<int>* front = q.front();
            q.pop();
            if (front == NULL)
            {
                cout << "NULL ";
            }
            else
            {
                cout << front->data << " ";
            }
            
            for (int i=0; i < front->children.size(); i++)
            {
                q.push(front->children[i]);
            }
        
        }
    }
}

int main()
{
    // treenode<int>* root = new treenode<int>(1);
    // treenode<int>* node1 = new treenode<int>(2);
    // treenode<int>* node2 = new treenode<int>(3);
    // treenode<int>* node3 = new treenode<int>(4);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // root->children.push_back(node3);
 
    treenode<int>* root = insertTree();   //Enter this: 1 3 2 3 4 1 5 1 8 1 10 2 6 7 1 9 1 11 0 0 0 1 12 1 13 0
    cout << endl;
    levelordertraversal(root);
    // int c = countleafnodes(root);
    // cout << "no of leaf nodes: " << c << endl;1
    delete root;
    

}