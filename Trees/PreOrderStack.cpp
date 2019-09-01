/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(A == NULL) return ans;
    stack<TreeNode* > sta;
    TreeNode* temp = A;
    do
    {
        if(temp)
        {
            ans.push_back(temp->val);
            sta.push(temp);
            if(temp->left) temp = temp->left;
            else 
            {
                if(!sta.empty())
                    while(!sta.empty())
                    {
                        temp = sta.top();
                        sta.pop();
                        if(temp->right) {
                            temp = temp->right;
                            break;
                        }
                        else temp = NULL;
                    }
                else return ans;
            }
        }
    }
    while(temp);
    return ans;
}
