int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0;
    int j = 0;
    int k = 0;
    int ans = INT_MAX;
    while(i<A.size() && j<B.size() && k < C.size())
    {
        int temp = max(A[i],B[j]);
        temp = max(temp,C[k]);
        int temp2 = min(A[i],B[j]);
        temp2 = min(temp2,C[k]);
        ans = min(ans,temp-temp2);
        if(temp2 == A[i]) i++;
        else if(temp2 == B[j]) j++;
        else k++;
    }
    return ans;
    
}
