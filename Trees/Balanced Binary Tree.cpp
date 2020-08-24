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

int solve(TreeNode* A){
    if(A == NULL) return -1;
    if(A->left == NULL && A->right == NULL) return 0;
    int left = solve(A->left);
    int right = solve(A->right);
    if(llabs((long long int) left-(long long int)right) > 1) ans = 0;
    return max(left, right)+1;
}

int Solution::isBalanced(TreeNode* A) {
    ans = 1;
    solve(A);
    return ans;
}