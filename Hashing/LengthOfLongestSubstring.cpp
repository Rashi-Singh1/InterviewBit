int Solution::lengthOfLongestSubstring(string A) {
    int start = 0, end = 0, ans = 0;
    unordered_map<char,int> m;
    for(end = 0 ; end < A.size(); end++){
        if(m.count(A[end]) > 0){
            start = max(start, m[A[end]]+1);            //VI : missed the point, that start should not be rewinded
        }
        m[A[end]] = end;
        ans = max(ans, end-start+1);
    }
    return ans;
}