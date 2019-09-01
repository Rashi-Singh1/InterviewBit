/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* ans = NULL;
    ListNode* head = NULL;
    while(A && B)
    {
        if(A->val < B->val)
        {
            if(ans) {
                ans->next = A;
                ans = ans->next;
            }
            else {
                head = A;
                ans = A;
            }
            A = A->next;
        }
        else{
            
            if(ans) {
                ans->next = B;
                ans = ans->next;
            }
            else {
                ans = B;
                head = B;
            }
            B = B->next;
        }
    }
    while(A)
    {
        if(ans) {
            ans->next = A;
            ans = ans->next;
        }
        else {
            head = A;
            ans = A;
        }
        A = A->next;
    }
    while(B)
    {
         if(ans) {
            ans->next = B;
            ans = ans->next;
        }
        else {
            ans = B;
            head = B;
        }
        B = B->next;
    }
    return head;
}
