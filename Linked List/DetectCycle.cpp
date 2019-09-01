/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if(!A) return A;
    ListNode * cur = A;
    ListNode * nex = A->next;
    while(cur)
    {
        if(cur == nex) break;
        if(cur) cur = cur->next;
        else return NULL;
        if(nex && nex->next) nex = nex->next->next;
        else return NULL;
    }
    if(cur) nex = cur->next;
    else return NULL;
    long long int size = 1;
    while(nex!=cur)
    {
        size++;
        nex = nex->next;
    }
    cur = A;
    nex = A;
    while(size > 0)
    {
        nex = nex->next;
        size--;
    }
    if(cur == nex) return cur;
    while(cur!=nex)
    {
        nex = nex->next;
        cur = cur->next;
        if(cur == nex) return cur;
    }
    return NULL;
}