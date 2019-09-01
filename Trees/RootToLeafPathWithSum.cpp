/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//did not worked for all test cases tho

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > ans;
    if(A == NULL) return ans;
    long long int sum = 0;
    stack<TreeNode* > sta;
    TreeNode* temp = A;
    vector<int> array;
    while(temp)
    {
        sta.push(temp);
        array.push_back(temp->val);
        sum+=temp->val;
        if(temp->left) temp = temp->left;
        else{
            if(!sta.empty()){
                while(!sta.empty())
                {
                    temp = sta.top()->right;
                    TreeNode* trash = sta.top();
                    sta.pop();
                    if(temp) break;
                    else{
                        if(trash->left == NULL && sum == (long long int) B) ans.push_back(array);
                        sum-=array[array.size()-1];
                        array.pop_back();
                        while(!sta.empty() && array.size() >0 && array[array.size()-1]!=sta.top()->val) {
                            sum-=array[array.size()-1];
                            array.pop_back();
                        }
                    }
                }
            }else{
                return ans;
            }
        }
    }
    return ans;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//actual ans
vector<vector<int> >ans;
void solve(TreeNode* A, long long int sum, int B,vector<int>& temp)
{
    if(A == NULL) return;
    sum+=(long long int)A->val;
    if(A->left == NULL && A->right == NULL && sum == B)
    {
        ans.push_back(temp);
        return;
    }
    
    if(A->left) {
        temp.push_back(A->left->val);
        solve(A->left,sum,B,temp);
        temp.pop_back();
    }
    if(A->right)
    {
        temp.push_back(A->right->val);
        solve(A->right,sum,B,temp);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    ans.clear();
    vector<int> temp;
    if(A == NULL) return ans;
    
    temp.push_back(A->val);
    solve(A,0,B,temp);
    return ans;
}
