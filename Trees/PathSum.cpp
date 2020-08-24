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
typedef long long ll;
void solve(TreeNode*A, ll sum, ll cur){
    if(A == NULL || ans == 1) return;
    cur+=(ll)(A->val);
    if(A->left == NULL && A->right == NULL && sum == cur) {ans = 1; return;}
    solve(A->left, sum, cur);
    solve(A->right, sum, cur);
}

int Solution::hasPathSum(TreeNode* A, int B) {
    ans = 0;
    solve(A, (ll)B, 0);
    return ans;
}