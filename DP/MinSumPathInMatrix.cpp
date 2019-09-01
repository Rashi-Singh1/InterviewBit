int Solution::minPathSum(vector<vector<int> > &A) {
    if(A.size() == 0) return 0;
    if(A[0].size() == 0) return 0;
    for(int i = 0;i<A.size();i++)
    {
        for(int j = 0;j<A[i].size();j++)
        {
            if(i == 0 && j == 0) continue;
            int Min;
            if(i > 0) Min = A[i-1][j];
            if(j > 0) {
                if(i == 0) Min = A[i][j-1];
                else Min = min(Min,A[i][j-1]);
            }
            A[i][j] = Min + A[i][j];
        }
    }
    return A[A.size()-1][A[0].size()-1];
}
