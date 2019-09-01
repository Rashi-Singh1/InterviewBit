int Solution::candy(vector<int> &A) {
    if(A.size() == 0) return 0;
    map<int,vector<int> > sta;
    for(int i = 0;i<A.size();i++)
    {
        sta[A[i]].push_back(i);
    }
    int ans = 0;
    int cur = 1;
    vector<int> sol (A.size(),-1);
    for(auto x : sta)
    {
        for(auto y : x.second)
        {
            int Max = 0;
            if(y-1 >=0) if(sol[y-1]!=-1 && A[y-1] < A[y]) Max = sol[y-1];
            if(y+1 < A.size()) if(sol[y+1]!=-1 && A[y+1] < A[y]) Max =  max(Max,sol[y+1]);
            sol[y] = Max+1;
            ans+=sol[y];
        }
    }
    return ans;
}