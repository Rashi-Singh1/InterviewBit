vector<vector<int> >ans;

void print(vector<bool>& temp)
{
    for(auto x: temp) cout<<x<<" ";
    cout<<endl;
}

void solve(vector<int>& A,int done, vector<int>& temp, int i,vector<bool>& cond)
{
    if(done == 0)
    {
        ans.push_back(temp);
        return;
    }
    for(int j = 0;j<A.size();j++)
    {
        if(cond[j] == true) continue;
        temp.push_back(A[j]);
        cond[j] = true;
        solve(A,done-1,temp,j,cond);
        temp.pop_back();
        cond[j] = false;
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
   ans.clear();
   if(A.size() == 0) return ans;
   sort(A.begin(),A.end());
   vector<bool> cond(A.size(),false);
   for(int i = 0;i<A.size();i++)
   {
       vector<int> temp;
       temp.push_back(A[i]);
       cond[i] = true;
       solve(A,A.size()-1,temp,i,cond);
       cond[i] = false;
   }
   return ans;
}