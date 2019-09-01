
//After Reset
int Solution::maxSubArray(const vector<int> &A) {
    if(A.size() == 0) return 0;
    bool allNeg = true;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] >=0) allNeg = false;
    }
    if(allNeg == true)
    {
        int max = A[0];
        for(int i = 1;i<A.size();i++)
        {
            if(max < A[i]) max = A[i];
        }
        return max;
    }
    else
    {
        int lMax = A[0];
        int gMax = A[0];
        for(int i = 1;i<A.size();i++)
        {
            if(lMax < 0)
            {
                lMax = A[i];
            }
            else{
                lMax+=A[i];
            }
            gMax = max(gMax,lMax);
        }
        gMax = max(gMax, lMax);
        return gMax;
    }
}