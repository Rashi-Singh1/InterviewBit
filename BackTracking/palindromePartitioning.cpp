vector<vector<string> > ans;
void solve(string A, vector<string>& temp, int i)
{
    if(i == A.size()) 
    {
        ans.push_back(temp);
        return;
    }
    string str = "";
    for(int j = i;j<A.size();j++)
    {
        str.push_back(A[j]);
        string blah = str;
        reverse(str.begin(),str.end());
        string trash = blah;
        blah = str;
        str = trash;
        if(str == blah)
        {
            temp.push_back(str);
            solve(A,temp,j+1);
            temp.pop_back();
        }else continue;
    }
}

vector<vector<string> > Solution::partition(string A) {
    ans.clear();
    if(A.size() == 0) return ans;
    string str = "";
    vector<string> temp;
    solve(A,temp,0);
    return ans;
}