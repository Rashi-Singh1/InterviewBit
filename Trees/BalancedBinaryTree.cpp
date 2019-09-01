/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int ans;
int solve(TreeNode* A)
{
    if(A == NULL) return 0;
    if(A->left == NULL && A->right == NULL) return 1;
    int lHeight = solve(A->left);
    int rHeight = solve(A->right);
    if(abs(lHeight-rHeight) > 1) ans = 0;
    return max(lHeight,rHeight)+1;
}

int Solution::isBalanced(TreeNode* A) {
    if(A == NULL) return 1;
    ans = 1;
    int trash = solve(A);
    return ans;
}
