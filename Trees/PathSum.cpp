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
void solve(TreeNode* A, long long int parentSum, int B)
{
    if(A == NULL) return;
    if(A->left == NULL && A->right == NULL)
    {
        if(parentSum == (long long int)B) ans = 1;
    }
    if(A->left) solve(A->left,parentSum+(long long int)A->left->val,B);
    if(A->right) solve(A->right,parentSum+(long long int)A->right->val,B);
}

int Solution::hasPathSum(TreeNode* A, int B) {
    if(A == NULL) return 0;
    ans = 0;
    solve(A,(long long int)A->val,B);
    return ans;
}
