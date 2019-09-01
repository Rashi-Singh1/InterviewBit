/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(!A || B == 0) return A;
    long long int size = 0;
    ListNode* temp = A;
    while(temp)
    {
        size++;
        temp = temp->next;
    }
    B = B%size;  //imp point that i missed earlier
    size = size-B;
    if(size == 0) return A; //another imp point
    temp = A;
    while(temp)
    {
        if(temp->next == NULL)
        {
            temp->next = A;
            break;
        }
        temp = temp->next;
    }
    temp = A;
    while(size > 1)
    {
        temp = temp->next;
        size--;
    }
    A = temp->next;
    temp->next = NULL;
    return A;
}
