int Solution::trap(const vector<int> &A) {
    vector<int> right(A.size(),-1);
    int lMax = -1;
    for(int i = A.size()-1;i>=0;i--)
    {
        if(lMax == -1) {
            right[i] = lMax;
            lMax = A[i];
        }
        else{
            if(lMax >= A[i]) right[i] = lMax;
            else {
                right[i] = -1;
                lMax = A[i];
            }
        }
    }
    lMax = -1;
    long long int ans = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(lMax>=A[i] && right[i]!=-1) ans+=(min(lMax,right[i])-A[i]);
        else lMax = A[i];
    }
    return (int)ans;
}
