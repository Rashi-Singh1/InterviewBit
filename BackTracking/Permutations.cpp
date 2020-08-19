void solve(vector<vector<int> >& ans, vector<int>& temp, vector<int>& A, vector<int>& count){
    if(temp.size() == A.size()){
        ans.push_back(temp);
        return;
    }    
    for(int i = 0 ; i < A.size(); i++){
        if(count[i] > 0){
            count[i] = 0;
            temp.push_back(A[i]);
            solve(ans, temp, A, count);
            count[i] = 1;
            temp.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> >ans;
    vector<int> temp, count(A.size(),1);
    solve(ans, temp, A, count);
    return ans;
}