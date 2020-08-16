/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* slow = A, *fast = A;
    bool loop = false;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next == NULL ? NULL : fast->next->next;
        if(slow == fast){
            loop = true;
            break;
        }
    }
    if(loop){
        fast = A;
        while(slow && fast && slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}
