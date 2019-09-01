/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(!A) return A;
    ListNode * cur = A;
    ListNode * temp = A->next;
    ListNode * head = A;
    while(temp)
    {
        if(cur->val > temp->val)
        {
            ListNode * trash = head;        //imp point head might change, do not make this A
            ListNode * prev = NULL;
            while(trash && trash->val < temp->val)
            {
                prev = trash;
                trash = trash->next;
            }
            if(prev){   //notice that we r not changing cur here, bcs temp pe kaam ho rha h, usko abhi bhi cur se compare karenge ex 4 66 2 3 cur = 66 and temp = 2, jab 2 aage lag gya 3 ko bade numb that is cur = 66 se compare karenge
                cur->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
                if(cur) temp = cur->next;
                else temp = NULL;
            }
            else{
                cur->next = temp->next;
                temp->next = head;
                head = temp;
                if(cur) temp = cur->next;
                else temp = NULL;
            }
        }
        else{
            cur = temp;
            temp = cur->next;
        }
    }
    return head;
}
