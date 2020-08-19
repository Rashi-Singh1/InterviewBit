/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int b, int c) {
    ListNode* prev = NULL, *left = NULL, *cur = A, *end = NULL, *head = A, *nex = NULL;
    int count = 1;
    while(count < b){
        count++;
        prev = cur;
        cur = cur->next;
    }
    left = prev; end = cur;
    prev = NULL;
    while(cur && count <= c){
        count++;
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
        nex = cur == NULL ? NULL : cur->next;
    }
    if(left)left->next = prev;
    else head = prev;
    if(end) end->next = cur;
    return head;
}