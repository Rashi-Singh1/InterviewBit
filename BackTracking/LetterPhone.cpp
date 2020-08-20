void solve(vector<string>& ans, vector<string>& com, string temp, string A, int cur){
    if(cur == A.size()){
        ans.push_back(temp);
        return;
    }
    int num = (int)(A[cur]-'0');
    for(int i = 0; i < com[num].size(); i++){
        temp.push_back(com[num][i]);
        solve(ans, com, temp, A, cur+1);
        temp.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> com = {"0", "1", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string temp;
    solve(ans, com, temp, A, 0);
    return ans;
}