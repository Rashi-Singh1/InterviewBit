/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int postIndex;
TreeNode* solve(vector<int> &post, vector<int> &in, int start, int end){
    if(start <= end && postIndex < post.size()){
        int ind = start;
        for(ind = start; ind <= end; ind++){
            if(in[ind] == post[postIndex]) break;
        }
        postIndex--;
        TreeNode* root = new TreeNode(in[ind]);
        root->right = solve(post, in, ind+1, end);
        root->left = solve(post, in, start, ind-1);
        return root;
    }
    else return NULL;
}

TreeNode* Solution::buildTree(vector<int> &in, vector<int> &post) {
    postIndex = post.size()-1;
    return solve(post, in, 0, in.size()-1);
}