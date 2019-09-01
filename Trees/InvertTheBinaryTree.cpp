/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve(TreeNode* A)
{
    if(A == NULL) return;
    TreeNode* temp = A->left;
    A->left = A->right;
    A->right = temp;
    solve(A->left);
    solve(A->right);
}

TreeNode* Solution::invertTree(TreeNode* A) {
    if(A == NULL) return A;
    solve(A);
    return A;
}
