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
stack<t> s;
BSTIterator::BSTIterator(TreeNode *root) {
    while(!s.empty()) s.pop();
    if(root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !s.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    int ans = -1;
    if(!s.empty()){
        t top = s.top(); t right = top->right;
        ans = top->val;
        s.pop();
        while(right) {
            s.push(right);
            right = right->left;
        }
    }
    return ans;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */