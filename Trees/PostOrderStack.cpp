/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(A == NULL) return ans;
    TreeNode*  temp = A;
    stack<TreeNode* >sta;
    stack<TreeNode* >sta2;
    while(temp)
    {
        if(temp)
        {
            sta.push(temp);
            if(temp->left) temp = temp->left;
            else{
                if(!sta.empty()){
                    while(!sta.empty())
                    {
                        temp = sta.top()->right;
                        sta2.push(sta.top());
                        sta.pop();
                        if(temp == NULL)
                        {
                            while(!sta2.empty())
                            {
                                if(sta.empty()) break;
                                else{
                                    if(!sta2.empty() && sta.top()->left == sta2.top()) {
                                        ans.push_back(sta2.top()->val);
                                        sta2.pop();
                                        break;
                                    }
                                    else if(!sta2.empty())
                                    {
                                        ans.push_back(sta2.top()->val);
                                        sta2.pop();
                                    }
                                }
                            }
                        }
                        else break;
                    }
                }
                else {
                    while(!sta2.empty())
                    {
                        ans.push_back(sta2.top()->val);
                        sta2.pop();
                    }
                    return ans;
                }
            }
        }
    }
    while(!sta2.empty())
    {
        ans.push_back(sta2.top()->val);
        sta2.pop();
    }
    return ans;
}

//a much easier answer, do node right and left and the in the end reverse the ans
vector<int> Solution::postorderTraversal(TreeNode* A) {
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
            if(temp->right) temp = temp->right;
            else 
            {
                if(!sta.empty())
                    while(!sta.empty())
                    {
                        temp = sta.top();
                        sta.pop();
                        if(temp->left) {
                            temp = temp->left;
                            break;
                        }
                        else temp = NULL;
                    }
                else {
                    reverse(ans.begin(),ans.end());
                    return ans;
                }
            }
        }
    }
    while(temp);
    reverse(ans.begin(),ans.end());
    return ans;
}
