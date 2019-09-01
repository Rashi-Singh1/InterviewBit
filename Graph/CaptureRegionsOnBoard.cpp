void Solve(int x, int y,vector<vector<char> >& A)
{
    if(A[x][y] == 'O'){
        A[x][y] = '!';
        if(x > 0) Solve(x-1,y,A);
        if(x+1 < A.size()) Solve(x+1,y,A);
        if(y > 0) Solve(x,y-1,A);
        if(y+1 < A[0].size()) Solve(x,y+1,A);
    }
    else return;
}

void Solution::solve(vector<vector<char> > &A) {
    if(A.size() == 0) return;
    if(A[0].size() == 0) return;
    for(int i = 0;i<A.size();i++)
    {
        Solve(i,0,A);
        Solve(i,A[i].size()-1,A);
    }
    for(int i = 0;i<A[0].size();i++)
    {
        Solve(0,i,A);
        Solve(A.size()-1,i,A);
    }
    for(int i =0;i<A.size();i++)
    {
        for(int j = 0;j<A[i].size();j++)
        {
            if(A[i][j] == '!') A[i][j] = 'O';
            else if(A[i][j] == 'O') A[i][j] = 'X';
        }
    }
}