// { Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


 // } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    Node* rr(Node* root){
        cout << "rr : " << root->data;
        Node* temp = root;
        root = root->right;
        temp->right = root->left;
        root->left = temp;
        return root;
    }
    Node* rl(Node* root){
        cout << "rl" << root->data;
        Node* temp = root;
        Node* r = root->right;
        root = root->right->left;
        r->left = root->right;
        root->right = r;
        temp->right = root->left;
        root->left = temp;
        return root;
    }
    Node* ll(Node* root){
        cout << "ll:" << root->data;
        Node* temp = root;
        root=root->left;
        temp->left = root->right;
        root->right = temp;
        return root;
    }
    
    Node* lr(Node* root){
        cout << "lr:" << root->data;
        Node* temp = root;
        Node* l = root->left; 
        root = root->left->right;
        l->right = root->left;
        root->left = l;
        temp->left = root->right;
        root->right = temp;
        return root;
    }
    
    unordered_map<Node*, int> heights;

    int height(Node* root){
        if(!root){
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    Node* insertToAVL(Node* root, int key)
    {

        if(!root){
            Node* node = new Node(key);
            cout << "created" << key << " ";
            return node;
        }
 
        else if(key < root->data){
            cout << " left ";
            root->left = insertToAVL(root->left, key);
        }
        else if(key > root->data){
            cout << " right ";
            root->right = insertToAVL(root->right, key);
        }
        else{
            return root;
        }
        
        int bf;
        if(root->left && root->right){
            bf = height(root->right) - height(root->left);
        }
        else if(!root->left){
            bf =  height(root->right);
        }
        else{
            bf = -height(root->left);
        }
        // cout << " backto:bf" << bf << ":" << root->data << " ";
        // cout << "heightof" << root->data << "left:" << height(root->left) << ":right:"<<height(root->right) << " ";
        
        if(root->right && bf > 1 && key > root->right->data){
            //rr
            root = rr(root);
        }
        else if(root->right && bf > 1 && key < root->right->data){
            //rl
            root = rl(root);
        }
        else if(root->left && bf < -1 && key < root->left->data){
            //ll
            root = ll(root);
        }
        else if(root->left && bf < -1 && key > root->left->data){
            //lr
            root = lr(root);
        }
        else{
            // do nothing
            // cout << "donthg ";
        }
        
        
        
        return root;
        
        
    }
};

// { Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}  // } Driver Code Ends


/*
1
7
850 859 912 50 218 545 8
*/
/*
1
6
850 859 912 50 218 545
*/

/*
1
9
850 859 912 50 218 545 815 22 903
*/
/*
1
5
984 286 587 377 286
*/
/*
1
4
984 286 587 377
*/

/*
1
9
572 337 731 441 305 999 30 508 12
*/