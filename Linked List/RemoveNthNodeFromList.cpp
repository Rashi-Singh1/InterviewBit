/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode * head = A;
    if(!head || B <=0 ) return head;
    long long int size = 0;
    while(head)
    {
        size++;
        head = head->next;
    }
    long long int index = size - 1ll*B;
    head = A;
    if(index <=0 ) return A->next;
    while(index > 1)
    {
        head = head->next;
        index--;
    }
    if(head && head->next) head->next = head->next->next;
    else head->next = NULL;
    return A;
}
