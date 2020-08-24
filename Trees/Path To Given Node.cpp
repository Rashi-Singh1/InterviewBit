/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool done;
void dfs(vector<int>& ans, TreeNode*A , int B){
    if(done) return;
    if(A == NULL) return;
    ans.push_back(A->val);
    if(A->val == B) {done = true; return;}
    dfs(ans, A->left, B);
    dfs(ans, A->right, B);
    if(!done) ans.pop_back();
}
vector<int> Solution::solve(TreeNode* A, int B) {
    done = false;
    vector<int> ans;
    dfs(ans, A, B);
    return ans;
}