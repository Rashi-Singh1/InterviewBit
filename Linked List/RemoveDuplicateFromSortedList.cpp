/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL) return A;
    ListNode * B = A;
    while(A->next)
    {
        if(A->val == A->next->val) A->next = A->next->next;
        else A = A->next;
    }
    return B;
}
