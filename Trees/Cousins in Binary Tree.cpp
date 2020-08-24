/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int l;
void solve2(map<int, vector<int> >& s, TreeNode* A, int B, int level){
    if(A == NULL) return;
    if(A->val !=B) s[level].push_back(A->val);
    if(A->val == B) l = level;
    if(!(A->left && A->left->val == B)) solve2(s, A->right, B, level+1);
    if(!(A->right && A->right->val == B)) solve2(s, A->left, B, level+1);
}

vector<int> Solution::solve(TreeNode* A, int B) {
    l = -1;
    vector<int> ans;
    map<int, vector<int> > s;
    solve2(s, A, B, 0);
    if(l >=0) for(auto x : s[l]) ans.push_back(x);
    return ans;
}