/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B <= 1) return A;
    if(!A) return A;
    if(B == 2)
    {
        ListNode * prev = NULL;
        ListNode * cur = A;
        ListNode * nex = A->next;
        ListNode * start = A;
        while(nex)
        {
            cur->next = nex->next; 
            nex->next = cur; 
            if(prev) prev->next = nex;
            else start = nex;
            prev = cur;
            cur = cur->next; 
            if(cur) nex = cur->next; 
            else nex = NULL;
        }
        return start;
    }
    ListNode * prev = NULL;
    ListNode * cur = A;
    ListNode * nex = A->next;
    ListNode * start = A;
    ListNode * end = A;
    ListNode * head = A;
    bool setHead = false;
    int count = B;
    while(count > 1)
    {
        count--;
        end = end->next;
    }
    count = B;
    while(B > 0 && cur)      //reversing here
    {
        nex = cur->next;
        cur->next = prev;
        if(end) end = end->next;
        prev = cur;
        cur = nex;
        if(nex) nex = nex->next;
        if(B == 1) {
            if(setHead == false) {
                head = prev; 
                setHead = true;
            }
            B = count+1;
            start->next = end;
            start = cur;
        }
        B--;
    }
    return head;
}
