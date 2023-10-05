/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
                // STEP 1: PASS 1
        // Creating a copy of each old node and insert it next to the old node in the same linked list.
        // Not copying the random pointer information yet
        // e.g 1->2->3 would be 1->1->2->2->3->3
        Node* curr=head;
        Node* temp;
        while(curr){
            temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            curr=temp;
        }
        
        // STEP 2: PASS 2
        // Copy the random pointers from the older nodes.
        curr=head;
        while(curr && curr->next){
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next; // go to next old curr
        }
        
        //STEP 3: PASS 3
        // Copy the alternative currs into "ans" link list using the "helper" pointer along with restoring the old link list.
        Node* Original=head; // first curr is a dummy curr
        Node* copy=head->next;
        temp=copy;
    
        while(head && Original && Original->next){
                       
            // Restoring the old linklist, by removing the alternative newly added currs
            Original->next=Original->next->next;
            // Copy the alternate added currs from the old linklist
            copy->next=copy->next? copy->next->next : copy->next; 
            Original=Original->next; // go to next alternate curr  
			copy=copy->next; 
        }
        return temp;

    }
};