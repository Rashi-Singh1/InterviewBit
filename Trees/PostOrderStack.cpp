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
                                    //this will allow us to stop popping elements when left subtree for element in sta.top() is done
                                    //don't need to stop after right subtree, bcs after right subtree, we anyway need to pop the center
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
    stack<t> s;
    while(A){
        s.push(A);
        ans.push_back(A->val);
        if(A->right) A = A->right;
        else{
            if(s.empty()) return ans;
            while(!s.empty()){
                A = s.top()->left;
                s.pop();
                if(A) break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//Morris
typedef TreeNode* t;
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    t cur = A;
    while(cur){
        if(cur->right == NULL){
            ans.push_back(cur->val);
            cur = cur->left;
        }else{
            t prev = cur->right;
            while(prev->left && prev->left!=cur) prev = prev->left;
            if(prev->left == NULL) {
                prev->left = cur;
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                prev->left = NULL;
                cur = cur->left;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}