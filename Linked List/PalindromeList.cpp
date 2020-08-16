/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef long long int ll;
ListNode* reverse(ListNode* A) {
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

int Solution::lPalin(ListNode* A) {
    ll size = 0;
    ListNode* copy = A, *prev = NULL;
    while(copy){
        size++;
        copy = copy->next;
    }
    copy = A;
    size = (size + 1)/2;
    while(size > 0){
        size--;
        prev = copy;
        copy = copy->next;
    }
    prev->next = reverse(copy);
    copy = prev->next;
    while(A && copy){
        if(A->val!=copy->val) return 0;
        A = A->next;
        copy = copy->next;
    }
    return 1;
}