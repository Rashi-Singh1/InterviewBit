vector<vector<string> >ans;

bool isSafe(int A,int pos, int next,vector<string>& temp)
{
    //check diagonals and stuff
    for(int i = 0;i<next;i++)
    {
        if(pos+next-i <A) if(temp[i][pos+next-i] == 'Q') return false;
        if(i+pos-next <A) if(temp[i][i+pos-next] == 'Q') return false;
        if(temp[i][pos] == 'Q') return false;
    }
    return true;
}

void solve(int A,int next,vector<string>& temp)
{
    if(next == A){
        ans.push_back(temp);
        return;
    }
    string trash;
    for(int i = 0;i<A;i++) trash.push_back('.');
    for(int i = 0;i<A;i++)
    {
        if(isSafe(A,i,next,temp))
        {
            trash[i] = 'Q';
            temp.push_back(trash);
            solve(A,next+1,temp);
            temp.pop_back();
            trash[i] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    ans.clear();
    string trash;
    for(int i = 0;i<A;i++) trash.push_back('.');
    if(A == 0) return ans;
    for(int i = 0;i<A;i++)
    {
        vector<string> blah;
        trash[i] = 'Q';
        blah.push_back(trash);
        solve(A,1,blah);
        trash[i] = '.';
    }
    return ans;
}