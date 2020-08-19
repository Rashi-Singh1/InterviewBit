void solve(vector<vector<int> >& ans, vector<int>& temp, vector<int>& A, int cur){
    ans.push_back(temp);
    int trash = INT_MIN;
    for(int i = cur; i< A.size(); i++){
        while(trash!=INT_MIN && i < A.size() && A[i] == trash) i++;
        if(i == A.size()) continue;
        temp.push_back(A[i]);
        solve(ans, temp, A, i+1);
        temp.pop_back();
        trash = A[i];
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(ans, temp, A, 0);
    return ans;
}
