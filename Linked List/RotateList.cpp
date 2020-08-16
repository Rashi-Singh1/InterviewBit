/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A == NULL || A->next == NULL) return A;
    int s = 0;
    ListNode *copy = A, *cur = A, *nex = A->next, *head = NULL; 
    while(copy){
        s++;
        copy = copy->next;
    }
    B%=s;
    if(B == 0) return A;
    B = s-B;
    while(B > 1){
        cur = cur->next;
        nex = cur == NULL ? NULL : cur->next;
        B--;
    }
    cur->next = NULL;
    head = nex;
    while(nex && nex->next){
        nex = nex->next;
    }
    if(nex) nex->next = A;
    return head;
}