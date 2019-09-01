int Solution::maxArea(vector<int> &A) {
    if(A.size() <= 1 ) return 0;
    int i = 0;
    int j = A.size()-1;
    long long int ans = 0;
    while(i<j)
    {
        ans = max(ans,(long long int)(min(A[i],A[j]))*((long long int)j-i));
        if(A[i] > A[j]) j--;
        else i++;
    }
    return ans;
}
