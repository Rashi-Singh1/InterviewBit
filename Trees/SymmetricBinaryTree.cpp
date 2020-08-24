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

void solve(TreeNode* A, TreeNode* B){
    if(ans == 0) return;
    if(A == NULL && B == NULL) return;
    if(A == NULL || B == NULL) {ans = 0; return;}
    if(A->val!=B->val){ans = 0; return;}
    solve(A->left, B->right);
    solve(A->right, B->left);
}

int Solution::isSymmetric(TreeNode* A) {
    ans = 1;
    solve(A, A);
    return ans;
}