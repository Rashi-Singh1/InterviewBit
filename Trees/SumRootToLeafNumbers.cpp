/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long long int ans;
long long int mod;
void solve(TreeNode* A, long long int temp)
{
    if(A == NULL) return;
    temp = ((temp*1ll*10)%mod + (long long int)A->val)%mod;
    if(A->left == NULL && A->right == NULL)
    {
        ans = (ans + (temp%mod))%mod;
        return;
    }
    solve(A->left,temp);
    solve(A->right,temp);
}

int Solution::sumNumbers(TreeNode* A) {
    ans = 0;
    if(A == NULL) return ans;
    mod = (long long int)1003;
    solve(A,0);
    return ans%1003;
}
