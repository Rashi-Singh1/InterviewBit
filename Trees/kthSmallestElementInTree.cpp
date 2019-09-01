/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = -1;
    if(A == NULL) return ans;
    int done = 0;
    stack<TreeNode* > sta;
    TreeNode* temp = A;
    while(temp)
    {
        sta.push(temp);
        if(temp->left) temp = temp->left;
        else{
            if(sta.empty()) return ans;
            else {
                while(!sta.empty())
                {
                    temp = sta.top()->right;
                    done++;
                    if(done == B) {
                        ans = sta.top()->val;
                        return ans;
                    }
                    sta.pop();
                    if(temp != NULL) break;
                }
            }
        }
    }
    return ans;
}
