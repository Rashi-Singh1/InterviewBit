/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    if(A == NULL || A->next == NULL) return A;
    ListNode* head = reverseList(A->next);		//gives the head of the reversed linked list on the right
    A->next->next = A;							//make changes for current node
    A->next = NULL;
    return head;
}