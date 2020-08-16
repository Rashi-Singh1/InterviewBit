/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef long long int ll;
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode *ta = A, *tb = B;
    ll sa = 0, sb = 0;
    while(ta){
        sa++;
        ta = ta->next;
    }
    while(tb){
        sb++;
        tb = tb->next;
    }
    ta = A; tb = B;
    while(sa > sb){
        ta = ta->next;
        sa--;
    }
    while(sb > sa){
        tb = tb->next;
        sb--;
    }
    while(sa > 0 && tb!=ta){
        ta = ta->next;
        tb = tb->next;
        sa--;
    }
    return ta;
}