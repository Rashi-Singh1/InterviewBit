/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//earlier i thought i had to make 3 partitions, hence this shit
ListNode* Solution::partition(ListNode* A, int B) {
    if(!A) return A;
    ListNode * prev = NULL;
    ListNode * nex = NULL;
    ListNode * end = NULL;
    ListNode * temp = A;
    ListNode * head = A;
    while(temp)
    {
        if(temp->val < B)
        {
            if(prev){
                if(end)
                {
                    end->next = temp->next;
                    temp->next = prev->next;
                    prev->next = temp;
                    prev = temp;
                    temp = end->next;
                }
                else{
                    if(nex)
                    {
                        nex->next = temp->next;
                        temp->next = prev->next;
                        prev->next = temp;
                        prev = temp;
                        temp = nex->next;
                    }
                    else{
                        prev = temp;
                        temp = temp->next;
                    }
                }
            }
            else{
                if(end)
                {
                    end->next = temp->next;
                    temp->next = head;
                    head = temp;
                    prev = temp;
                    temp = end->next;
                }
                else{
                    if(nex)
                    {
                        nex->next = temp->next;
                        temp->next = head;
                        head = temp;
                        prev = temp;
                        temp = nex->next;
                    }
                    else{
                        prev = temp;
                        temp = temp->next;
                    }
                }
            }
        }
        else if(temp->val == B)
        {
            if(nex){
                if(end)
                {
                    end->next = temp->next;
                    temp->next = nex->next;
                    nex->next = temp;
                    nex = temp;
                    temp = end->next;
                }
                else{
                    nex = temp;
                    temp = temp->next;
                }
            }
            else{
                if(end)
                {
                    if(prev)
                    {
                        end->next = temp->next;
                        temp->next = prev->next;
                        prev->next = temp;
                        nex = temp;
                        temp = end->next;
                    }
                    else{
                        end->next = temp->next;
                        temp->next = head;
                        head = temp;
                        nex = temp;
                        temp = end->next;
                    }
                }
                else{
                    nex = temp;
                    temp = temp->next;
                }
            }
        }
        else{
            end = temp;
            temp = temp->next;
        }
    }
    return head;
}

//Only two partitions were needed, so this is the simpler version
ListNode* Solution::partition(ListNode* A, int B) {
    if(!A) return A;
    ListNode * prev = NULL;
    ListNode * end = NULL;
    ListNode * temp = A;
    ListNode * head = A;
    while(temp)
    {
        if(temp->val < B)
        {
            if(prev){
                if(end)
                {
                    end->next = temp->next;
                    temp->next = prev->next;
                    prev->next = temp;
                    prev = temp;
                    temp = end->next;
                }
                else{
                    prev = temp;
                    temp = temp->next;
                }
            }
            else{
                if(end)
                {
                    end->next = temp->next;
                    temp->next = head;
                    head = temp;
                    prev = temp;
                    temp = end->next;
                }
                else{
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
        else{
            end = temp;
            temp = temp->next;
        }
    }
    return head;
}
