int Solution::bulbs(vector<int> &A) {
    int count = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(count&1)
        {
            A[i] = A[i]^1;
        }
        if(A[i] == 0) count++;
    }
    return count;
}
