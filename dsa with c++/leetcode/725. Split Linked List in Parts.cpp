  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // divide the list into lengthOfNode/k sets and add 1 extra node for lengthOfNode%k sets from beginnning 
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> ans;
        int length = 0;
        ListNode* temp = head;
        while(temp){
            length++; temp = temp->next;
        }
        int quotient = length/k;
        int remainder = length%k;

        temp = head;
        for(int j=0; j<k; j++){
            int lengthOfSet = quotient;
            if(remainder){
                lengthOfSet++; remainder--;
            }
            if(lengthOfSet){
                ans.push_back(temp);
                for(int i=0; i<lengthOfSet-1; i++) temp = temp->next;

                ListNode* last = temp;
                temp = temp->next;
                last->next = nullptr;
            }
            else{
                ans.push_back(nullptr);
            }
        }
        return ans;
    }
};