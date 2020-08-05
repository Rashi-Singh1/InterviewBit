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
    vector<vector<int> >ans;
    if(A == NULL) return ans;
    stack<TreeNode* >left;
    stack<TreeNode* >right;
    left.push(A);
    bool leftTurn = true;
    while(!left.empty() || !right.empty()){
        vector<int> temp;
        while(!left.empty()){
            TreeNode* top = left.top();
            temp.push_back((top)->val);
            if(top->left) right.push(top->left);
            if(top->right) right.push(top->right);
            left.pop();
        }
        if(temp.size() > 0) ans.push_back(temp);    
        vector<int> temp2;
        while(!right.empty()){
            TreeNode* top = right.top();
            temp2.push_back((top)->val);
            if(top->right) left.push(top->right);
            if(top->left) left.push(top->left);
            right.pop();
        }
        if(temp2.size() > 0) ans.push_back(temp2);
    }
    return ans;
}

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
