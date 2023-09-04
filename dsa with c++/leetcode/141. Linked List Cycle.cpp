/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* turtle = head;
        ListNode* rabbit = head;

        while(rabbit && rabbit->next){
            turtle = turtle->next;
            rabbit = rabbit->next->next;
            if(turtle == rabbit) return true;
        }
        return false;
    }
};