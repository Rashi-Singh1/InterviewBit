/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans;
   if(A == NULL) return ans;
   TreeNode* first = NULL; TreeNode* second = NULL;
   TreeNode* val1 = NULL; TreeNode* val2 = NULL;
   TreeNode* cur = A;
   while(cur)
   {
       if(cur->left == NULL)
       {
           if(val1 == NULL) val1 = cur;
           else {
               if(val2 == NULL) val2 = cur;
               else {
                   val1 = val2;
                   val2 = cur;
               }
               if(val1->val > val2->val)
               {
                   if(first == NULL)
                   {
                       first = val1;
                       second = val2;
                   }
                   else{
                       second = val2;
                   }
               }
           }
           cur = cur->right;
       }
       else{
           TreeNode* pred = cur->left;
           while(pred->right && pred->right!=cur)
           {
               pred = pred->right;
           }
           if(pred->right == NULL)
           {
               pred->right = cur;
               cur = cur->left;
           }
           else{
               pred->right = NULL;
               if(val1 == NULL) val1 = cur;
               else {
                   if(val2 == NULL) val2 = cur;
                   else {
                       val1 = val2;
                       val2 = cur;
                   }
                   if(val1->val > val2->val)
                   {
                       if(val1->val > val2->val)
                       {
                           if(first == NULL)
                           {
                               first = val1;
                               second = val2;
                           }
                           else{
                               second = val2;
                           }
                       }
                   }
               }
               cur = cur->right;
           }
       }
   }
   if(first!= NULL)
   {
       ans.push_back(first->val);
       ans.push_back(second->val);
   }
   sort(ans.begin(),ans.end());
   return ans;
}
