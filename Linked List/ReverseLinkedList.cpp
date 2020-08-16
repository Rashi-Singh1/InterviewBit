/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    if(A == NULL) return A;
    ListNode* cur = A, *next = A->next, *prev = NULL;
    while(cur){
        cur->next = prev;
        prev = cur;
        cur = next;
        next = cur == NULL ? NULL : cur->next;
    }
    return prev;
}
