/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
typedef TreeLinkNode* t;
void Solution::connect(TreeLinkNode* A) {
    if(A == NULL) return;
    t parent = A, start = NULL;
    if(A->left) A = A->left;
    else A = A->right;
    start = A;
    while(start){
        A = start;
        while(A){
            while(parent){
                if(parent->left && A!=parent->left && A!=parent->right) {A->next = parent->left; break;}
                else if(parent->right && A!= parent->right) {A->next = parent->right; break;}
                else parent = parent->next;
            }
            A = A->next;
        }
        parent = start;
        bool startUpdated = false;
        while(start && startUpdated == false){
            if(start->left) {start = start->left; startUpdated = true;}
            else if(start->right) {start = start->right; startUpdated = true;}
            else start = start->next;
        }
    }
}
