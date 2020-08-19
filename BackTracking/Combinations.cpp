void solve(vector<vector<int> >& ans,int k, int A, vector<int>& temp){
    if(temp.size() == k) {
        ans.push_back(temp);
        return;
    }
    int start = temp.size() == 0 ? 0 : temp[temp.size()-1];
    for(int i = start; i < A; i++){
        temp.push_back(i+1);
        solve(ans, k,A, temp);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int k) {
    vector<vector<int> > ans;
    vector<int>temp;
    solve(ans, k, A, temp);
    return ans;
}


//for intern
vector<vector<int> > ans;

void solve(int range, int k, int i, vector<int>& temp)
{
    if(k == 0){
        ans.push_back(temp);
    }
    for(int j = i+1;j<=range;j++ )
    {
        temp.push_back(j);
        solve(range,k-1,j,temp);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combine(int range, int k) {
    ans.clear();
    if(k == 0)
    {
        vector<int> temp;
        ans.push_back(temp);
        return ans;
    }
    for(int i = 1;i<=range;i++)
    {
        vector<int>temp;
        temp.push_back(i);
        solve(range,k-1,i,temp);
    }
    return ans;
}
