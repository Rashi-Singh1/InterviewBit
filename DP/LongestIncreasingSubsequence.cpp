int Solution::lis(const vector<int> &A) {
    vector<int> ans (A.size(),1);
    int sol = 1;
    for(int i = 1;i<A.size();i++)
    {
        for(int j = i-1;j>=0;j--)
        {
            if(A[j] < A[i]) ans[i] = max(ans[i],ans[j]+1);
        }
        sol = max(sol,ans[i]);
    }
    return sol;
}
