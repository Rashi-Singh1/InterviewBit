int Solution::maxProfit(const vector<int> &A) {
    if(A.size() < 2) return 0;
    int profit = 0;
    int start = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] < A[start]) start = i;
        profit=max(profit,A[i]-A[start]);
    }
    return profit;
}
