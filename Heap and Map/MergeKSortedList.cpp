/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef pair<int, ListNode* > p;
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode* head = NULL, *cur = NULL;
    priority_queue<p, vector<p>, greater<p> > q;
    for(auto x : A) if(x) q.push({x->val, x});
    while(!q.empty()){
        auto x = q.top().second;
        q.pop();
        if(head){
            cur->next = x;
            cur = cur->next;
        }
        else{
            head = cur = x;
        }
        if(x->next) q.push({x->next->val, x->next});
    }
    return head;
}