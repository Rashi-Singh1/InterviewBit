/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(vector<int>& A, int start, int end){
    if(start <= end){
        int index = start;
        for(int i = start+1; i <= end; i++) if(A[index] < A[i]) index = i;
        TreeNode* root = new TreeNode(A[index]);
        root->left = solve(A, start, index-1);
        root->right = solve(A, index+1, end);
        return root;
    }
    return NULL;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    return solve(A, 0, (int)A.size()-1);
}