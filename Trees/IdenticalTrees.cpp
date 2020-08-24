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
typedef TreeNode* t;
void solve(t a, t b){
    if(ans == false) return;
    if(a == NULL && b == NULL) return;
    if(a == NULL || b == NULL) ans = 0;
    else {
        if(a->val != b->val) {ans = 0; return;}
        solve(a->left, b->left);
        solve(a->right, b->right);
    }
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    ans = 1;
    solve(A, B);
    return ans;
}

//smaller code
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A == NULL && B == NULL) return 1;
    if(A == NULL || B == NULL) return 0;
    return (A->val == B->val) && isSameTree(A->left,B->left) && isSameTree(A->right,B->right);
}
