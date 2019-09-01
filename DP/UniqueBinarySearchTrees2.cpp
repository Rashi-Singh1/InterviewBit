int Solution::numTrees(int A) {
    vector<int> ans(A+1,1);
    for(int i = 2;i<=A;i++)
    {
        ans[i] = 0;
        for(int j = 1;j<=i;j++)
        {
            ans[i]+=(ans[j-1]*ans[i-j]);
        }
    }
    return ans[A];
    
}