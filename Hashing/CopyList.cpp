/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    unordered_map<RandomListNode*, RandomListNode*> s;
    RandomListNode* cur = A, *head = NULL, *curcopy = NULL;
    while(cur){
        if(head == NULL) head = curcopy = new RandomListNode(cur->label);
        else {
            curcopy->next = new RandomListNode(cur->label);
            curcopy = curcopy->next;
        }
        s[cur] = curcopy;
        cur = cur->next;
    }
    cur = A;
    while(cur){
        s[cur]->random = cur->random == NULL ? NULL : s[cur->random];
        cur = cur->next;
    }
    return head;
}