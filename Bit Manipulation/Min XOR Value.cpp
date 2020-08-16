int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int ans = INT_MAX, temp;
    for(int i = 0 ; i < A.size()-1; i++){
        temp = A[i]^A[i+1];
        ans = min(ans,temp);
    }
    return ans;
}
