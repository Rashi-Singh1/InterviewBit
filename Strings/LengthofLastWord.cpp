int Solution::lengthOfLastWord(const string A) {
    if(A.size() == 0) return 0;
    int k = A.size()-1;
    while(k>=0)
    {
        if(A[k] == ' ') k--;
        else break;
    }
    int ans = 0;
    for(int i = k;i>=0;i--)
    {
        if(A[i]!=' ') ans++;
        else break;
    }
    return ans;
}
