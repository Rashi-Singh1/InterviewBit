/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* solve(TreeNode* root)
{
    if(root == NULL) return NULL;
    TreeNode* head = root;
    TreeNode* trash = root->right;
    root->right = solve(root->left);
    root->left = NULL;
    while(root->right)
    {
        root = root->right;
    }
    root->right = trash;
    TreeNode* blah = solve(trash);
    return head;
}

TreeNode* Solution::flatten(TreeNode* A) {
    if(A == NULL) return NULL;
    TreeNode* root = solve(A);
    return root;
}