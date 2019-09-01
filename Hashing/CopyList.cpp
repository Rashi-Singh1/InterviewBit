/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(!A) return A;
    RandomListNode* ans;
    RandomListNode* head;
    unordered_map<RandomListNode*,RandomListNode*> sta;
    RandomListNode* temp = A;
    while(temp)
    {
        RandomListNode* cute = new RandomListNode(temp->label);
        sta.insert(make_pair(temp,cute));
        temp = temp->next;
    }
    temp = A;
    ans = sta.find(temp)->second;
    head = ans;
    while(temp)
    {
        if(temp->next) ans->next = sta.find(temp->next)->second;
        if(temp->random) ans->random = sta.find(temp->random)->second;
        ans = ans->next;
        temp = temp->next;
    }
    return head;
}
