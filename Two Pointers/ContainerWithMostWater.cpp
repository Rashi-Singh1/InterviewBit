int Solution::maxArea(vector<int> &A) {
    long long int start = 0, end = A.size()-1;
    long long int ans = 0;
    while(start <= end){
        ans = max(ans, (end-start)*min(A[start], A[end]));
        if(A[start] <= A[end]) start++;
        else end--;
    }
    return ans;
}

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
