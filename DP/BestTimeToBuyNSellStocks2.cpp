int Solution::maxProfit(const vector<int> &A) {
    if(A.size() < 2) return 0;
    int profit = 0;
    for(int i = 0;i<A.size()-1;i++)
    {
        if(A[i] < A[i+1]) profit+=(A[i+1]-A[i]);
    }
    return profit;
}
