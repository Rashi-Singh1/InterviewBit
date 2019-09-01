/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(A == NULL) return ans;
    TreeNode*  temp = A;
    stack<TreeNode* >sta;
    while(temp)
    {
        if(temp)
        {
            sta.push(temp);
            if(temp->left) temp = temp->left;
            else{
                if(!sta.empty())
                    while(!sta.empty())
                    {
                        ans.push_back(sta.top()->val);
                        temp = sta.top()->right;
                        sta.pop();
                        if(temp!= NULL) break;
                    }
                else return ans;
            }
        }
    }
    return ans;
}
