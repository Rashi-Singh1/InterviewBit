/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(!A) return A;
    if(A->next == NULL) return A;
    ListNode * prev = NULL;
    ListNode * cur = A;
    ListNode * nex = A->next;
    ListNode * start = A;
    while(nex)
    {
        cur->next = nex->next; 
        nex->next = cur; 
        if(prev) prev->next = nex;
        else start = nex;
        prev = cur;
        cur = cur->next; 
        if(cur) nex = cur->next; 
        else nex = NULL;
    }
    return start;
}
