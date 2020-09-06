int Solution::maxProfit(const vector<int> &A) {
    if(A.size() < 2) return 0;
    int start = 0, end = 0, ans = 0;
    for(end = 0; end < A.size(); end++){
        if(A[end]- A[start] > ans) ans = A[end]-A[start];
        if(A[end] < A[start]) start = end;
    }
    return ans;
}