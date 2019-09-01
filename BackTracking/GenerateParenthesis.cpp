vector<string> ans;

void solve(int A, vector<int>& sta, string temp, long long int length,vector<char>& cha)
{
    if(length == 1ll*2*(long long int)A)
    {
        ans.push_back(temp);
        return;
    }
    for(int i = 0;i<cha.size();i++)
    {
        if(sta[0]>= sta[1] && i == 1) continue;
        if(sta[i] > 0) {
            temp.push_back(cha[i]);
            sta[i]--;
        }
        else continue;
        solve(A,sta,temp,length+1,cha);
        if(temp[temp.size()-1] == ')') sta[1]++;
        else sta[0]++;
        temp.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int A) {
    ans.clear();
    vector<int> sta(2,A);
    vector<char> cha = {'(',')'};
    if(A == 0) return ans;
    string temp = "(";
    sta[0]--;
    solve(A,sta,temp,1,cha);
    return ans;
}
