/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//way 1: not suitable when depth of tree >>> no of nodes on a level, bcs recursion 
vector<vector<int> > ans;

void solve(TreeNode* A, int level){
    if(A == NULL) return;
    if(ans.size() == level) ans.push_back(vector<int>(1,A->val));
    else ans[level].push_back(A->val);
    solve(A->left, level+1);
    solve(A->right, level+1);
}

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    ans.clear();
    solve(A, 0);
    return ans;
}

//way 2:
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> >ans;
    if(A == NULL) return ans;
    queue<pair<TreeNode* ,int> > q;
    q.push({A, 0});
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(ans.size() == x.second) ans.push_back(vector<int> (1,x.first->val));
        else ans[x.second].push_back(x.first->val);
        if(x.first->left) q.push({x.first->left, x.second+1});
        if(x.first->right) q.push({x.first->right, x.second+1});
    }
    return ans;
}
