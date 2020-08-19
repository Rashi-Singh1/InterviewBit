typedef long long int ll;
void solve(vector<vector<int> >& ans, vector<int>& temp, vector<int>& A, int ind, int sum, long long int cur){
    if(cur == sum){
        ans.push_back(temp);
        return;
    }
    if(cur > sum) return;
    int trash = -1;
    for(int i = ind; i < A.size(); i++){
        while(trash!= -1 && trash == A[i] && i < A.size()) i++;     //to prevent duplicates
        if(i == A.size()) continue;
        if((ll)A[i] + cur > (ll)sum) break;
        temp.push_back(A[i]);
        solve(ans, temp, A, i+1,sum, (ll)A[i] + cur);
        temp.pop_back();
        trash = A[i];
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int sum) {
    vector<vector<int> >ans;
    vector<int> temp;
    sort(A.begin(), A.end());
    solve(ans, temp, A, 0, sum, 0);
    return ans;
}

//for intern
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
    int trash = -1;
    for(int j = i+1;j<A.size();j++)
    {
        if(trash == A[j]) continue;
        temp.push_back(A[j]);
        solve(A,j,sum-A[j],temp);
        trash = temp[temp.size()-1];
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
