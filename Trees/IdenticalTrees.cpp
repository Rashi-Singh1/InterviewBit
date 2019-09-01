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
void solve(TreeNode* A, TreeNode* B)
{
    if(A == NULL && B == NULL) {
        return;
    }
    if(A == NULL || B == NULL)
    {
        ans = 0;
        return;
    }
    if(A->val != B->val) {
        ans = 0;
        return;
    }
    solve(A->left,B->left);
    solve(A->right, B->right);
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A == NULL && B == NULL) return 1;
    if(A == NULL || B == NULL) return 0;
    ans = 1;
    solve(A,B);
    return ans;
}

//smaller code
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A == NULL && B == NULL) return 1;
    if(A == NULL || B == NULL) return 0;
    return (A->val == B->val) && isSameTree(A->left,B->left) && isSameTree(A->right,B->right);
}
