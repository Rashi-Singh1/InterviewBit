/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
typedef TreeNode* t;
void solve2(t A, map<int,vector<int> > &ans, int slope){
    if(A == NULL) return;
    ans[slope].push_back(A->val);
    solve2(A->left, ans, slope+1);
    solve2(A->right, ans, slope);
} 

vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int> > store;
    vector<int> ans;
    solve2(A, store, 0);
    for(auto x : store) for(auto y : x.second) ans.push_back(y);
    return ans;
}