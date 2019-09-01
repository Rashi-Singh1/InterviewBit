
void solve(vector<int> &A, vector<vector<int> >&ans, int i,vector<int> & temp)
{
    for(int j = i+1;j<A.size();j++)
    {
        temp.push_back(A[j]);
        solve(A,ans,j,temp);
        ans.push_back(temp);
        temp.pop_back();
    }
}

// bool compare( const vector<int>& v1, const vector<int>& v2 ) { 
//     return (v1[0] < v2[0] || (v1[0] == v2[0] && v))
// } 
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> temp;
    ans.push_back(temp);
    if(A.size() == 0) return ans;
    sort(A.begin(),A.end());
    for(int i = 0;i<A.size();i++)
    {
        vector<int> temp = {A[i]};
        ans.push_back(temp);
        solve(A,ans,i,temp);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
}


//actual answer using dfs and no need of sort or using unique
void solve(vector<int> &A,vector<vector<int> > &ans,vector<int> &temp, int j)
{
    if(j == A.size()) {
        ans.push_back(temp);
        return;
    }
    solve(A,ans,temp,A.size()); 
    bool used = false;
    int trash = -1;
    for(int i = j+1;i<A.size();i++)
    {
        if(A[i] == trash && used) continue;
        temp.push_back(A[i]);
        solve(A,ans,temp,i);
        trash = temp[temp.size()-1];    //only need this trash, compare with popped value, is same then no need to repeat process
        used = true;
        temp.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> temp;
    ans.push_back(temp);
    if(A.size() == 0) return ans;
    sort(A.begin(),A.end());
    for(int i = 0;i<A.size();i++)
    {
        temp.push_back(A[i]);
        solve(A,ans,temp,i);
        temp.pop_back();
        int j = i+1;
        while(j < A.size())
        {
            if(A[j] == A[i]) j++;
            else break;
        }
        i = j-1;
    }
    return ans;
}