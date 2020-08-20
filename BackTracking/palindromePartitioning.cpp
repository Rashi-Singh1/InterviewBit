void solve(vector<vector<string>>& ans, vector<string> temp, string A){
    if(A.size() == 0){
        ans.push_back(temp);
        return;
    }
    string cur, rcur;
    for(int i = 1 ; i <= A.size(); i++){
        rcur = cur = A.substr(0,i);
        reverse(rcur.begin(), rcur.end());
        if(rcur == cur){
            temp.push_back(cur);
            string remain = A.substr(i);
            solve(ans, temp, remain);
            temp.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > ans;
    vector<string> temp;
    solve(ans, temp, A);
    return ans;
}