/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    if(A.size() == 0) return NULL;
    map<int,vector<int> > sta;
    for(int i = 0;i< A.size();i++)
    {
        if(A[i] == NULL) continue;
        else sta[A[i]->val].push_back(i);
    }
    ListNode* root = NULL,*head = NULL;
    while(sta.size() > 0)
    {
        if(sta.begin() == sta.end()) return head;
        auto x = sta.begin()->second;
        auto y = sta.begin()->first;
        int index = -1;
        if(head == NULL)
        {
            head = new ListNode(y);
            root = head;
        }
        else{
            root->next = new ListNode(y);
            root = root->next;
        }
        index = x[x.size()-1];
        if(x.size() > 1) sta.begin()->second.pop_back();
        else {
            sta[y].clear();
            sta.erase(y);
        }
        if(index!=-1)
        {
            A[index] = A[index]->next;
            if(A[index]!=NULL) sta[A[index]->val].push_back(index);
        }
    }
    return head;
}