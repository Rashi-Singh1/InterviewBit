/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
