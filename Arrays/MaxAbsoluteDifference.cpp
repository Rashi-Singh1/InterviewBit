int Solution::maxArr(vector<int> &A) {
    if(A.size() == 0) return 0;
    long long int lmin = A[0],lmax = A[0],mmin = A[0],mmax = A[0];
    for(int i = 1 ; i < A.size(); i++){
        lmin = min(lmin,(long long int)A[i]*1ll-i*1ll);
        lmax = max(lmax,(long long int)A[i]*1ll-i*1ll);
        mmin = min(mmin,(long long int)A[i]*1ll+i*1ll);
        mmax = max(mmax,(long long int)A[i]*1ll+i*1ll);
    }
    return (int)max(llabs(lmax-lmin),llabs(mmax-mmin));
}
