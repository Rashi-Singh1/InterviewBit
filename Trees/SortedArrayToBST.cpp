/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(const vector<int>& A, int start, int end)
{
    if(end < start) return NULL;
    int mid = (start+end)/2;
    TreeNode* root = NULL;
    root = new TreeNode(A[mid]);
    root->left = solve(A,start,mid-1);
    root->right = solve(A,mid+1,end);
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if(A.size() == 0) return NULL;
    TreeNode* root = NULL;
    root = solve(A,0,A.size()-1);
    return root;
}