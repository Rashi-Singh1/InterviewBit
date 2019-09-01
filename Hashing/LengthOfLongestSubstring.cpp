int Solution::lengthOfLongestSubstring(string A) {
    int ans = 0;
    unordered_map<char,int> sta;
    int start = 0;
    int end = 0;
    while(end < A.size())
    {
        if(sta.count(A[end]) && sta[A[end]] >= start)
        {
            start = sta[A[end]]+1;
        }
        else sta.insert(make_pair(A[end],end)); //wont update index, if A[end] is present, hence next line
        sta[A[end]] = end;
        ans = max(ans,end-start+1);
        end++;
    }
    return ans;
} 
