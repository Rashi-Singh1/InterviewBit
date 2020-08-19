/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    int s = 0, count = 0;
    ListNode*copy = A, *mid = NULL, *prev = NULL, *nex = NULL, *ans = NULL,*cur = NULL, *curnext = NULL;
    while(copy){
        s++;
        copy = copy->next;
    }
    s = (s+1)/2;
    copy = A;
    while(count < s){
        mid = copy;
        copy = copy->next;
        count++;
    }
    while(copy){
        nex = copy->next;
        copy->next = prev;
        prev = copy;
        copy = nex;
        nex = copy == NULL ? NULL : copy->next;
    }
    mid->next = NULL;
    cur = prev;
    copy = A;
    while(cur){
        nex = copy->next;
        curnext = cur->next;
        cur->next = nex;
        copy->next = cur;
        copy = nex;
        cur = curnext;
    }
    return A;
}
