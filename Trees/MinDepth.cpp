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

void solve(TreeNode* A, int parentHeight)
{
    if(A == NULL) return;
    if(A->left == NULL && A->right == NULL) 
    {
        if(ans!=-1) ans = min(ans,parentHeight);
        else ans = parentHeight;
    }
    solve(A->left,parentHeight+1);
    solve(A->right,parentHeight+1);
}

int Solution::minDepth(TreeNode* A) {
    ans = -1;
    if(A == NULL) return 0;
    solve(A,1);
    return ans;
}
