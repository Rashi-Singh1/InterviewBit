/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//iterative way O(n) time and O(h) space
int Solution::t2Sum(TreeNode* A, int B) {
    if(A == NULL) return 0;
    TreeNode* temp = A;
    TreeNode* temp2 = A;
    stack<TreeNode* >sta;
    stack<TreeNode* >sta2;
    queue<TreeNode*> less;
    queue<TreeNode*> more;
    while(temp && temp2)
    {
        sta.push(temp);
        if(temp->left) temp = temp->left;
        else{
            if(!sta.empty())
            {
                while(!sta.empty())
                {
                    temp = sta.top()->right;
                    less.push(sta.top());
                    sta.pop();
                    if(temp!=NULL) break;
                }
            }
            else{
                return 0;
            }
        }
        sta2.push(temp2);
        if(temp2->right) temp2 = temp2->right;
        else{
            if(!sta2.empty())
            {
                while(!sta2.empty())
                {
                    temp2 = sta2.top()->left;
                    more.push(sta2.top());
                    sta2.pop();
                    if(temp2!=NULL) break;
                }
            }
            else{
                return 0;
            }
        }
        while(!less.empty() && !more.empty())
        {
            if(less.front()->val + more.front()->val == B && less.front()!=more.front()) return 1;
            else if(less.front()->val + more.front()->val < B) less.pop();
            else more.pop();
        }
    }
    return 0;
}
