/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *head = NULL, *ans = NULL;
    int carry = 0;
    while(A && B){
        int temp = A->val + B->val + carry;
        A->val = temp%10;
        carry = temp/10;
        if(ans) {
            ans->next = A;
            ans = ans->next;
        }
        else{
            ans = A;
            head = ans;
        }
        A = A->next;
        B = B->next;
    }
    while(A){
        int temp = A->val + carry;
        A->val = temp%10;
        carry = temp/10;
        if(ans) {
            ans->next = A;
            ans = ans->next;
        }
        else{
            ans = A;
            head = ans;
        }
        A = A->next;
    }
    while(B){
        int temp = B->val + carry;
        B->val = temp%10;
        carry = temp/10;
        if(ans) {
            ans->next = B;
            ans = ans->next;
        }
        else{
            ans = B;
            head = ans;
        }
        B = B->next;
    }
    if(carry > 0) ans->next = new ListNode(carry);
    return head;
}