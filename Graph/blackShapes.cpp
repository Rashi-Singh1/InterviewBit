void Solve(int x, int y,vector<string>& A)
{
    if(A[x][y] == 'X'){
        A[x][y] = '!';
        if(x > 0) Solve(x-1,y,A);
        if(x+1 < A.size()) Solve(x+1,y,A);
        if(y > 0) Solve(x,y-1,A);
        if(y+1 < A[x].size()) Solve(x,y+1,A);
    }
    else return;
}

int Solution::black(vector<string> &A) {
    if(A.size() == 0) return 0;
    int count = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i].size() == 0) continue;
        else{
            for(int j = 0;j<A[i].size();j++)
            {
                if(A[i][j] == 'X'){
                    count++;
                    Solve(i,j,A);
                }
            }
        }
    }
    return count;
}