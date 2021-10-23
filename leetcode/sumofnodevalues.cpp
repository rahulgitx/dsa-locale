//https://leetcode.com/problems/add-two-numbers/submissions/

// vector or pointers : https://stackoverflow.com/questions/9090680/how-to-initialize-a-vector-of-pointers

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* p1=l1;
        int i = 0, v1 = 0;
        while(p1 != nullptr){
            v1 += (p1->val)*pow(10,i);
            p1 = p1->next;
            i++;
        }
        ListNode* p2 = l2;
        int j = 0, v2 = 0;
        while(p2 != nullptr){
            v2 += (p2->val)*pow(10,j);
            p2=p2->next;
            j++;
        }
        int sum = v1+v2;
        vector<int> v;
        while(sum != 0){
            v.push_back(sum%10);
            sum = sum/10;
        }
        ListNode* arr[v.size()];
        for (int j=0; j<v.size(); j++){
            arr[j]->val = v[j]; 
        }
        for (int j=0; j<(v.size()-1); j++){
            arr[j]->next = arr[j+1];
            if(j+1 == v.size()){
                arr[j+1]->next = nullptr;
            }
        }
        return arr[0];
    }
};

int main(){
    ListNode* arr[3];
    ListNode a(2);
    // cout << a.val;
    arr[0] = new ListNode();
    arr[0]->val = 1;
    // cout << arr[0]->val;
    arr[1] = new ListNode();
    arr[1]->val = 4;
    arr[2] = new ListNode();
    arr[2]->val = 6;
    arr[0]->next = arr[1];
    arr[1]->next = arr[2];
    arr[2]->next = nullptr;

    // cout << arr[0]->val;
    ListNode *p = arr[0];
    for (int i=0; i<3; i++){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    double x = 45;
    cout << x/2 << endl;

    vector<ListNode*> v;
    // v.reserve(1);
    v.push_back(new ListNode(85));
    cout << v[0]->val;
}



/*    -------------------- solution to problem ---------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        vector<ListNode*> v;
        unsigned int i=0, temp=0;
        unsigned int carry = 0, nod = 0;
        while((p1 != nullptr) || (p2 != nullptr)){
            if((p1 != nullptr) && (p2 != nullptr)){
                temp = p1->val + p2->val;
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1 == nullptr){
                temp = p2->val;
                p2=p2->next;
            }
            else{
                temp = p1->val;
                p1=p1->next;
            }
            if(temp<10){
                if(carry == 1){
                    temp += 1;
                    carry = 0;
                    if (temp == 10){
                        temp = 0;
                        carry = 1;
                    }
                }
                v.emplace_back(new ListNode(temp));
            }
            else{
                int newtemp = temp%10;
                if ( carry == 1){
                    newtemp += 1;
                }
                v.emplace_back(new ListNode(newtemp));
                carry = 1;
            }
            nod++; 
        }
        if (carry == 1){
            v.emplace_back(new ListNode(1));
        }
        for (int i=0; i<v.size(); i++){
            if(i == v.size()-1){
                v[i] == nullptr;
            }
            else{
                v[i]->next = v[i+1];
            }

        }
        
        
        return v[0];
    }
};
*/