int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A.size() == 0) return 0;
    if(A[0].size() == 0) return 0;
    if(A[0][0] == 1) return 0;
    else A[0][0] = -1;
    for(int i = 0;i<A.size();i++)
    {
        for(int j = 0;j<A[i].size();j++)
        {
            if(A[i][j] == 1) continue;
            int Min = A[i][j];
            if(i > 0 && A[i-1][j]!=1) Min = A[i-1][j];
            if(j > 0 && A[i][j-1]!=1) {
                if(i > 0 && A[i-1][j]!=1) Min+=A[i][j-1];
                else Min = A[i][j-1];
            }
            A[i][j] = Min;
        }
    }
    if(A[A.size()-1][A[0].size()-1] < 0) return -1*A[A.size()-1][A[0].size()-1];
    else return 0;
}
