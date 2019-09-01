/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    if(A == NULL) return ans;
    
    stack<TreeNode* > sta;
    stack<TreeNode* > sta2;
    sta.push(A);
    while(!(sta.empty() && sta2.empty()))
    {
        vector<int> temp;
        if(!sta.empty())
        {
            while(!sta.empty())
            {
                if(sta.top()->left) sta2.push(sta.top()->left);
                if(sta.top()->right) sta2.push(sta.top()->right);
                temp.push_back(sta.top()->val);
                sta.pop();
            }
            ans.push_back(temp);
        }else{
            while(!sta2.empty())
            {
                if(sta2.top()->right) sta.push(sta2.top()->right);
                if(sta2.top()->left) sta.push(sta2.top()->left);
                temp.push_back(sta2.top()->val);
                sta2.pop();
            }
            ans.push_back(temp);
        }
    }
    return ans;
}
