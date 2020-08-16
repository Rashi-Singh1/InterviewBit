/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    bool mul = false;
    ListNode *start = A, *prev = NULL;
    while(A && A->next){
        if(A->val == A->next->val){
            mul = true;
            if(prev) prev->next = A->next;
            else start = A->next;
        }else{
            if(mul){
                if(prev) prev->next = A->next;
                else start = A->next;
                mul = false;
            }else{
                prev = A;
            }
        }
        A = A->next;
    }
    if(mul){
        if(prev) prev->next = NULL;
        else start = NULL;
    }
    return start;
}


//Good question dobara dekh liyo
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A) return A;
    ListNode * temp = A;
    ListNode * start = A;
    ListNode * prev = NULL;
    bool mul = false;
    while(temp)
    {
        if(temp->next && temp->val == temp->next->val)
        {
            temp->next = temp->next->next;
            mul = true;
        }
        else{
            if(mul)
            {
                if(prev) {
                    prev->next = temp->next;
                }
                else start = temp->next;
            }
            else{
                prev = temp;
            }
            temp = temp->next;
            mul = false;
        }
    }
    return start;
}
