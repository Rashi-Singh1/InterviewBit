/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef long long int ll;
ll ans; ll mod;
void solve(TreeNode*A, ll cur){
    if(A == NULL) return;
    cur = ((cur*10ll)%mod + (ll)A->val)%mod;
    if(A->left == NULL && A->right == NULL) ans = (ans + cur)%mod;
    solve(A->left, cur);
    solve(A->right, cur);
}

int Solution::sumNumbers(TreeNode* A) {
    ans = 0; mod = 1003;
    solve(A, 0);
    return (int)(ans%mod);
}