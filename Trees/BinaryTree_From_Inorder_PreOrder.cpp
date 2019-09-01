/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int cur;
TreeNode* solve(vector<int>& pre, vector<int>& in,int start, int end)
{
    if(cur>= pre.size()) return NULL;
    TreeNode* root = new TreeNode(pre[cur]);
    for(int i = start;i<=end;i++)
    {
        if(in[i] == root->val)
        {
            if(i>start) {
                ++cur;
                root->left = solve(pre,in,start,i-1);
            }
            if(i<end) {
                ++cur;
                root->right = solve(pre,in,i+1,end);
            }
        }
    }
    return root;
}

TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) {
    if(pre.size() == 0) return NULL;
    cur = 0;
    TreeNode* root = solve(pre,in,0,pre.size()-1);
    return root;
}
