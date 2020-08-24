/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(const vector<int>&A, int start, int end){
    if(start <= end){
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(A[mid]);
        root->left = solve(A, start, mid-1);
        root->right = solve(A, mid+1, end);
        return root;
    }   
    return NULL;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return solve(A, 0, A.size()-1);
}