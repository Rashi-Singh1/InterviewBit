/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int preIndex;
TreeNode* solve(vector<int> &pre, vector<int> &in, int start, int end){
    if(start <= end && preIndex < pre.size()){
        int ind = start;
        for(ind = start; ind <= end; ind++){
            if(in[ind] == pre[preIndex]) break;
        }
        preIndex++;
        TreeNode* root = new TreeNode(in[ind]);
        root->left = solve(pre, in, start, ind-1);
        root->right = solve(pre, in, ind+1, end);
        return root;
    }
    else return NULL;
}

TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) {
    preIndex = 0;
    return solve(pre, in, 0, in.size()-1);
}