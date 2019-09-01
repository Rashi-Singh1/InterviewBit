vector<string> ans;

void solve(string A, string temp, vector<string>& sta, int i)
{
    if(i == A.size())
    {
        ans.push_back(temp);
        return;
    }
    int trash = A[i]-'0';
    for(int k = 0;k<sta[trash].size();k++)
    {
        temp.push_back(sta[trash][k]);
        solve(A,temp,sta,i+1);
        temp.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    ans.clear();
    if(A.size() == 0) return ans;
    vector<string> sta = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int trash = A[0]-'0';
    for(int j = 0;j<sta[trash].size();j++)
    {
        string temp = "";
        temp.push_back(sta[trash][j]);
        solve(A,temp,sta,1);
    }
    return ans;
}
