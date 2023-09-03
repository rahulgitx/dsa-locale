 */
 void rev(int a, int b, vector<int>& v){
     stack<int> st;
     for(int i=a; i<=b; i++){
         st.push(v[i]);
        //  cout << v[i] << " ";
     }
     for(int i=a; i<=b; i++){
        //  cout << st.top() << " ";
         v[i] = st.top(); st.pop();
     }
     return;
 }
ListNode* solve(ListNode* node, int k) {
    vector<int> v;
    ListNode* temp = node;
    while(temp){
        v.push_back(temp->val);
        temp = temp->next;
    }
    if(v.size() < k){
        k = v.size();
    }
    int i=0; 
    while(i < v.size() ){
        int a = i;
        int b;
        if(i+k-1 <= v.size()-1){
            b= i+k-1;
        }
        else{
            b = v.size()-1;
        }
        rev(a, b, v);
        // reverse(v.begin()+k, v.begin()-(i+k-1));
        i = i+k;
        // cout << i << ":";
    }
    cout << endl;

    ListNode* head = new ListNode;
    ListNode* t = head;

    for(int i=0; i<v.size(); i++){
        // cout << v[i] << " ";
        ListNode* n = new ListNode;
        n->val = v[i];
        t->next = n;
        t = t->next;
    }
    return head->next;
}