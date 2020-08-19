/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int k) {
    if(k < 2) return A;
    int count = 0;
    ListNode* prev = NULL, *cur = A, *nex = NULL, *head = NULL, *end = NULL;
    while(cur){
        nex = cur->next;
        cur->next = NULL;
        ListNode* start = cur;
        while(cur && count < k){
            cur->next = prev;
            prev =cur;
            cur = nex;
            nex = cur == NULL ? NULL : cur->next;
            count++;
        }
        if(end) end->next = prev;
        end = start;
        if(head ==  NULL) head = prev;
        prev = NULL;
        count = 0;
    }
    return head;
}