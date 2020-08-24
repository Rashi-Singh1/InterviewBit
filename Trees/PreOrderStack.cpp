/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode* t;
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<t> s;
    vector<int> ans;
    while(A){
        s.push(A);
        ans.push_back(A->val);
        if(A->left) A = A->left;
        else{
            if(s.empty()) return ans;
            while(!s.empty()){
                A = s.top()->right;
                s.pop();
                if(A) break;
            }
        }
    }
    return ans;
}

//way 2
typedef TreeNode* t;
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<t> s;
    if(A) s.push(A);
    while(!s.empty()){
        t cur = s.top();
        s.pop();
        ans.push_back(cur->val);
        if(cur->right) s.push(cur->right);
        if(cur->left) s.push(cur->left);
        
    }
    return ans;
}

//Morris
typedef TreeNode* t;
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    t cur = A;
    while(cur){
        if(cur->left == NULL){
            ans.push_back(cur->val);
            cur = cur->right;
        }else{
            t prev = cur->left;
            while(prev->right && prev->right!=cur) prev = prev->right;
            if(prev->right == NULL) {
                prev->right = cur;
                ans.push_back(cur->val);
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return ans;
}