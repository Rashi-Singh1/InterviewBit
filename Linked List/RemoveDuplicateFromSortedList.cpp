/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *head = A;
    while(A && A->next){
        if(A->val == A->next->val) A->next = A->next->next;
        else A = A->next;
    }
    return head;
}