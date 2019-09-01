/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int adder(int a, int b, int*carry)
{
    int c = a+b+(*carry);
    *carry = c/10;
    return c%10;
}

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    long long int sizea = 0;
    long long int sizeb = 0;
    ListNode * temp = A;
    while(temp)
    {
        sizea++;
        temp = temp->next;
    }
    temp = B;
    while(temp)
    {
        sizeb++;
        temp = temp->next;
    }
    ListNode * head = NULL;
    if(sizea > sizeb) {
        head = A;
        temp = A;
    }
    else {
        head = B;
        temp = B;
    }
    int carry = 0;
    ListNode * prev = NULL;
    while(A && B)
    {
        temp->val = adder(A->val,B->val,&carry);
        A = A->next;
        B = B->next;
        prev = temp;
        temp = temp->next;
    }
    while(A)
    {
        temp->val = adder(A->val,0,&carry);
        A = A->next;
        prev = temp;
        temp = temp->next;
    }
    while(B)
    {
        temp->val = adder(0,B->val,&carry);
        B = B->next;
        prev = temp;
        temp = temp->next;
    }
    if(carry)
    {
        if(temp) temp->val = carry;
        else {
            if(prev) prev->next = new ListNode(carry);
            else return NULL;
        }
    }
    temp = head;
    prev = NULL;
    while(temp)
    {
        if(temp->val !=0 ) prev = temp;
        temp = temp->next;
    }
    if(prev) prev->next = NULL;
    else{
        if((sizea | sizeb) > 0) head->next = NULL;
        else return NULL;
    }
    return head;
}
