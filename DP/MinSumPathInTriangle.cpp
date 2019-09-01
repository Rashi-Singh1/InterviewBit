int Solution::minimumTotal(vector<vector<int> > &A) {
    for(int i = 1;i<A.size();i++)
    {
        for(int j = 0;j<=i;j++)
        {
            if(j == 0) A[i][j]+=A[i-1][j];
            else if(j == i) A[i][j]+=A[i-1][j-1];
            else A[i][j] += min(A[i-1][j],A[i-1][j-1]);
        }
    }
    int Min = A[A.size()-1][0];
    for(int i = 1;i<A.size();i++)
    {
        Min = min(Min,A[A.size()-1][i]);
    }
    return Min;
}
