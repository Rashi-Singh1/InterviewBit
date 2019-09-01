vector<vector<int> >ans;

void print(vector<int>& temp)
{
    for(auto x: temp) cout<<x<<" ";
    cout<<endl;
}

void solve(vector<int> &A, int i,int sum,vector<int>& temp)
{
    if(sum < 0) return;
    if(i == A.size()) {
        if(sum == 0) ans.push_back(temp);
        return;
    }
    solve(A,A.size(),sum,temp);
    for(int j = i;j<A.size();j++)
    {
        if(j > 0 && A[j] == A[j-1]) continue;   //in this question since we r repeating even if present once, therefore, if duplicates originlly in vector, seedha skip, no need to push
        temp.push_back(A[j]);
        solve(A,j,sum-A[j],temp);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    ans.clear();
    if(B == 0 )
    {
        vector<int> temp;
        ans.push_back(temp);
    }
    sort(A.begin(),A.end());
    for(int i = 0;i<A.size();i++)
    {
        vector<int> temp;
        temp.push_back(A[i]);
        solve(A,i,B-A[i],temp);
        int j = i+1;
        while(j < A.size() && A[j] == A[i]) j++;
        i = j-1;
    }
    return ans;
}
