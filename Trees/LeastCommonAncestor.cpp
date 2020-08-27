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
void solve(TreeNode* A, int B, vector<int>& b){
    if(A == NULL || done) return;
    b.push_back(A->val);
    if(B == A->val) {done = true; return;}
    solve(A->left, B, b);
    solve(A->right, B, b);
    if(!done) b.pop_back();
}

int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> b,c; int ans = -1; done = false;
    solve(A,B,b); done = false;
    solve(A,C,c);
    for(int i = 0 ; i < min((int)b.size(), (int)c.size()); i++){
        if(b[i] == c[i]) ans = b[i];
        else break;
    }
    return ans;
}