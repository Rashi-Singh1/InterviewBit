/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve2(TreeNode* A, vector<int>& ans, int level){
    if(A == NULL) return;
    if(ans.size() <= level) ans.push_back(A->val);
    solve2(A->right, ans, level+1);
    solve2(A->left, ans, level+1);
}

vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    solve2(A, ans, 0);
    return ans;
}