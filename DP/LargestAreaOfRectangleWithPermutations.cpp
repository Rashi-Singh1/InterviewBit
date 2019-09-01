int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0) return 0;
    if(A[0].size() == 0) return 0;
    for(int i = 1;i<A.size();i++)
    {
        for(int j = 0;j<A[i].size();j++)
        {
            if(A[i][j] == 1) A[i][j] = A[i-1][j]+1;
        }
    }
    int row = A.size();
    for(int i = 0;i<row;i++)
    {
        int array[row+1];
        memset(array,0,sizeof(array));
        for(int j = 0;j<A[i].size();j++)
        {
            array[A[i][j]]++;
        }
        int k = 0;
        for(int j = row;j>=0;j--)
        {
            if(array[j]<=0) continue;
            while(array[j])
            {
                A[i][k++] = j;
                array[j]--;
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<row;i++)
    {
        int Min = A[i][0];
        ans = max(ans,Min);
        for(int j = 1;j<A[i].size();j++)
        {
            Min = min(Min,A[i][j]);
            ans = max(ans,Min*(j+1));
        }
    }
    return ans;
}
