/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int, vector<int> > s;
    queue<pair<TreeNode*, int> > q;
    vector<vector<int> >ans;
    if(A == NULL) return ans;
    q.push({A,0});
    while(!q.empty()){
        auto front = q.front();
        TreeNode* fnode= front.first; int l = front.second;
        s[l].push_back(fnode->val);
        q.pop();
        if(fnode->left) q.push({fnode->left, l-1});
        if(fnode->right) q.push({fnode->right, l+1}); 
    }
    for(auto x : s) {
        vector<int> temp;
        for(auto y : x.second) temp.push_back(y);
        ans.push_back(temp);
    }
    return ans;
}