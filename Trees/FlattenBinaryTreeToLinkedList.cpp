/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    if(A == NULL) return NULL;
    TreeNode *left = flatten(A->left), *right = flatten(A->right);
    A->left = NULL; A->right = left;
    while(left && left->right) left = left->right;
    if(left) left->right = right;
    else A->right = right;
    return A;
}