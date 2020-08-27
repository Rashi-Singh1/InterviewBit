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
vector<int> Solution::recoverTree(TreeNode* A) {
    int trash = INT_MIN, first = -1, last = -1; bool firstFound = false;
    t prev = NULL; t cur = A;
    while(cur){
        if(cur->left == NULL){
            if(trash != INT_MIN && trash > cur->val) {
                if(firstFound) last = cur->val;
                else {first = trash; last = cur->val; firstFound = true;}
            }
            trash = cur->val;
            cur = cur->right;
        }else{
            prev = cur->left;
            while(prev->right && prev->right!= cur) prev = prev->right;
            if(prev->right == NULL) {                   //this part occurs before covering left subtree
                prev->right = cur;
                cur = cur->left;
            }
            else {
                prev->right = NULL;                     //this part occurs after left subtree, therefore for inorder, root value pushed after left subtree
                if(trash != INT_MIN && trash > cur->val) {
                    if(firstFound) last = cur->val;
                    else {first = trash; last = cur->val; firstFound = true;}
                }
                trash = cur->val;
                cur = cur->right;
            }
        }
    }
    return {last,first};
}
