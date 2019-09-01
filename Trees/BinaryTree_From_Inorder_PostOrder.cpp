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
            if(i<end) {
                ++cur;
                root->right = solve(pre,in,i+1,end);
            }
            if(i>start) {
                ++cur;
                root->left = solve(pre,in,start,i-1);
            }
        }
    }
    return root;
}

TreeNode* Solution::buildTree(vector<int> &in, vector<int> &post) {
    if(post.size() == 0) return NULL;
    cur = 0;
    reverse(post.begin(),post.end());
    TreeNode* root = solve(post,in,0,post.size()-1);
    return root;
}
