/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode* makeTree(ListNode* A)
{
    if(A == NULL) return NULL;
    ListNode* temp = A;
    int size = 0;
    
    while(temp){
        temp = temp->next;
        size++;
    }
    temp = A;
    ListNode* prev = NULL;
    for(int i = 1;i<(size+1)/2;i++)
    {
        prev = temp;
        temp = temp->next;
    }
    TreeNode* root = new TreeNode(temp->val);
    ListNode* agla = temp->next;
    if(prev) prev->next = NULL;
    if(prev!=NULL) root->left = makeTree(A);
    else root->left = makeTree(prev);
    root->right = makeTree(agla);
    return root;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    return makeTree(A);
}

