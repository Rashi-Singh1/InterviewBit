int Solution::seats(string A) {
    vector<int> index;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == 'x') index.push_back(i);
    }
    if(index.size() < 2) return 0;
    int temp = index[index.size()/2];
    long long int ans = 0;
    long long int MOD = 10000003;
    int curIndex = index.size()/2 - 1;
    for(long long int i = temp-1;i>=0,curIndex>=0;i--,curIndex--)
    {
        ans+=(long long int)(i%MOD-(index[curIndex]*1ll)%MOD)%MOD;
    }
    curIndex = index.size()/2 + 1;
    for(int i = temp+1;i<index.size(),curIndex<index.size();i++,curIndex++)
    {
        ans+=(long long int)((index[curIndex]*1ll)%MOD-i%MOD)%MOD;        
    }
    return (int)(ans%MOD);
}
