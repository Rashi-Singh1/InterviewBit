/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    if(A == NULL) return ans;
    queue<TreeNode*> sta1;
    queue<TreeNode*> sta2;
    sta1.push(A);
    while(!(sta1.empty() && sta2.empty()))
    {
        vector<int> temp;
        if(!sta1.empty())
        {
            while(!sta1.empty())
            {
                temp.push_back(sta1.front()->val);
                if(sta1.front()->left) sta2.push(sta1.front()->left);
                if(sta1.front()->right) sta2.push(sta1.front()->right);
                sta1.pop();
            }
            ans.push_back(temp);
        }
        else if(!sta2.empty())
        {
            while(!sta2.empty())
            {
                temp.push_back(sta2.front()->val);
                if(sta2.front()->left) sta1.push(sta2.front()->left);
                if(sta2.front()->right) sta1.push(sta2.front()->right);
                sta2.pop();
            }
            ans.push_back(temp);
        }
    }
    return ans;
}
