vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> sta;
    vector<int> ans;
    
   for(int i = 0;i<A.size();i++)
   {
       bool flag = false;
       if(sta.empty()){
           ans.push_back(-1);
           sta.push(A[i]);
       }
       else{
           while(!sta.empty())
           {
               if(sta.top() < A[i]){
                   ans.push_back(sta.top());
                   sta.push(A[i]);
                   flag = true;
                   break;
               }
               else{
                   sta.pop();
               }
           }
           if(flag == false )
           {
               ans.push_back(-1);
               sta.push(A[i]);
           }
       }
   }
   return ans;
}
