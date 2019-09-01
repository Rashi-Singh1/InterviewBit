
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
vector<vector<int> > Solution::subsets(vector<int> &A) {
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
    return ans;
}


void print(vector<int>& temp)
{
    for(auto x: temp) cout<<x<<" ";
    cout<<endl;
}

//better solution bcs it uses dfs, therefore no need or sort in the end
void solve(vector<int> &A,vector<vector<int> > &ans,vector<int> &temp, int j)
{
    if(j == A.size()) {
        ans.push_back(temp);
        return;
    }
    solve(A,ans,temp,A.size()); //taking it to the end makes it dfs, otherwise would have taken all values pehle and ek karke pop karta
    for(int i = j+1;i<A.size();i++)
    {
        temp.push_back(A[i]);
        solve(A,ans,temp,i);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
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
    }
    return ans;
}
