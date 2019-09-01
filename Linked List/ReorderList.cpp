/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
void print(ListNode * head)
{
    while(head)
    {
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<endl;
}
ListNode* Solution::reorderList(ListNode* A) {
    if(!A) return A;
    if(A->next == NULL) return A;
    ListNode * temp = A;
    long long int size = 0;
    while(temp)
    {
        size++;
        temp = temp->next;
    }
    size = (size + 1ll)/(2*1ll);        //for size = 5 we modify it to 3 and for size = 4 we modify it to 2
    long long int trash = size-1;
    temp = A;
    while(size > 0)     //we calculate temp bcs temp se reverse karna h (including temp)
    {
        temp = temp->next;
        size--;
    }
    size = trash + 1ll;
    ListNode * joint = A;
    ListNode * end = A;
    while(end->next)    //we calculate joint bcs joint ke aage reverse karna h
    {
        if(trash > 0) joint = joint->next;
        end = end->next;
        trash--;
    }
    trash = size-1;
    joint->next = end;
    ListNode * prev = NULL;
    ListNode * cur = temp;
    ListNode * nex = temp->next;
    ListNode * head = A;
    while(cur)      //reversing here
    {
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
        if(nex) nex = nex->next;
    }
    temp = A;
    prev = NULL;
    while(size > 0)     //take the pointer to modified size in the new reversed list
    {
        size--;
        prev = temp;
        temp = temp->next;
    }
    cur = A;
    nex = cur->next;
    while(trash > 0)
    {
        prev->next = temp->next;
        cur->next = temp;
        temp->next = nex;
        cur = nex;
        if(cur) nex = cur->next;
        else nex = NULL;
        temp = prev->next;
        trash--;
    }
    return A;
}
