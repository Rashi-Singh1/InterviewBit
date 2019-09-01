/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//naive solution
TreeNode* solve(vector<int>&A, int start, int end)
{
    if(end < start) return NULL;
    int val = start;
    for(int i = start+1;i<=end;i++)
    {
        if(A[val] < A[i]) val = i;
    }
    TreeNode* root = new TreeNode(A[val]);
    root->left = solve(A, start,val-1);
    root->right = solve(A,val+1,end);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    if(A.size() == 0) return NULL;
    TreeNode* root = solve(A,0,A.size()-1);
    return root;
}
