/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void print(ListNode * head)
{
    while(head)
    {
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<endl;
}
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    if(!A) return A;
    ListNode * start = A;
    ListNode * end = A;
    ListNode * head = A;
    ListNode * begin = NULL;
    ListNode * finish = NULL;
    while(m > 1)
    {
        m--;
        begin = start;
        start = start->next;
    }
    while(n > 1)
    {
        n--;
        end = end->next;
    }
    finish = end->next;
    ListNode * cur = start;
    ListNode * nex = cur->next;
    ListNode * prev = NULL;
    while(cur && prev!=end)
    {
        cur->next = prev;
        prev = cur;
        cur = nex;
        if(cur) nex = cur->next;
        else nex = NULL;
    }
    if(begin) begin->next = end;
    else head = end;
    start->next = finish;
    return head;
    
}