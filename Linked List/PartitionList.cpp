/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *small = NULL, *large = NULL, *shead = NULL, *lhead = NULL, *nex = NULL;
    while(A){
        nex = A->next;
        A->next = NULL;
        if(A->val < B) {
            if(shead == NULL) shead = small = A;
            else {
                small->next = A;
                small = small->next;
            }
        }else{
            if(lhead == NULL) lhead = large = A;
            else {
                large->next = A;
                large = large->next;
            }
        }
        A = nex;
    }
    if(small) small->next = lhead;
    if(shead) return shead;
    return lhead;
}