//when no of holes is equal to no of mice
int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;
    for(int i = 0 ; i < A.size(); i++){
        ans=max(ans,abs(B[i]-A[i]));
    }
    return ans;
}

//if no of holes >  no of mice