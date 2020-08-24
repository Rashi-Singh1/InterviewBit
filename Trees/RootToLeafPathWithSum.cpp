/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
typedef long long ll;
void solve(vector<vector<int> >& ans, vector<int>& temp, TreeNode*A, ll B, ll cur){
    if(A == NULL) return;
    cur+=(ll)A->val;
    temp.push_back(A->val);
    if(A->left == NULL && A->right == NULL && cur == B) ans.push_back(temp);
    solve(ans, temp, A->left, B, cur);
    solve(ans, temp, A->right, B, cur);
    temp.pop_back();
} 

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > ans; vector<int> temp;
    solve(ans, temp, A, (ll)B, 0);
    return ans;
}