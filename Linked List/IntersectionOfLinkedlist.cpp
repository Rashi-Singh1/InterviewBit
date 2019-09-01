/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    long long int sizea = 0,sizeb = 0;
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
    ListNode * trash = NULL;
    long long int size = 0;
    if(sizea > sizeb)
    {
        trash = A;
        size = sizea-sizeb;
        temp = B;
    }else{
        trash = B;
        size = sizeb-sizea;
        temp = A;
    }
    while(size > 0)
    {
        size--;
        trash = trash->next;
    }
    while(trash && temp)
    {
        if(trash == temp) return temp;
        trash = trash->next;
        temp = temp->next;
    }
    return NULL;
}