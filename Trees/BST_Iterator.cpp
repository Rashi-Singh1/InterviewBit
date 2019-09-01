/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode* > sta;
BSTIterator::BSTIterator(TreeNode *root) {
    while(!sta.empty()) sta.pop();
    TreeNode* temp = root;
    while(temp)
    {
        sta.push(temp);
        temp = temp->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !sta.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    if(!sta.empty())
    {
        TreeNode* ans = sta.top();
        sta.pop();
        if(ans->right)
        {
            TreeNode* temp = ans->right;
            while(temp)
            {
                sta.push(temp);
                temp = temp->left;
            }
        }
        return ans->val;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
