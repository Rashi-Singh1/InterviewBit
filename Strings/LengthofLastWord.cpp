int Solution::lengthOfLastWord(const string A) {
    int end = A.size()-1;
    while(end >= 0){
        if(A[end] == ' ') end--;
        else break;
    }
    if(end < 0) return 0;
    else{
        for(int i = end; i >= 0; i--){
            if(A[i] == ' ') return end-i;
        }
    }
    return end+1;
}

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
