int Solution::diffPossible(vector<int> &A, int B) {
    int i = 0;
    int j = 0;
    if(B < 0) B = -1*B;
    if(B == 0)
    {
        for(int k = 0;k<A.size()-1;k++)
        {
            if(A[k]==A[k+1]) return 1;
        }
        return 0;
    }
    while(i<A.size() && j < A.size())
    {
        if(A[j]- A[i] == B) return 1;
        else if(A[j]-A[i] > B) i++;
        else j++;
    }
    return 0;
}