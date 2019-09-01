/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    if(!A) return A;
    ListNode * prev = NULL;
    ListNode * cur = A;
    ListNode * nex = A->next;
    ListNode * head = A;
    while(cur)      //reversing here
    {
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
        if(nex) nex = nex->next;
        else head = prev;
    }
    return head;
}
