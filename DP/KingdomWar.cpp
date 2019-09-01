int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0) return 0;
    if(A[0].size() == 0) return 0;
    int row = A.size();
    int col = A[0].size();
    int ans = A[row-1][col-1];
    for(int i = col-1;i>=0;i--)
    {
        for(int j = row-2; j>=0;j--)
        {
            A[j][i]+=A[j+1][i];
        }
    }
    for(int i = row-1;i>=0;i--)
    {
        for(int j = col-2;j>=0;j--)
        {
            A[i][j]+=A[i][j+1];
        }
    }
    for(int i = row-1;i>=0;i--)
    {
        for(int j = col-1;j>=0;j--)
        {
            ans = max(ans,A[i][j]);
        }
    }
    return ans;
}
