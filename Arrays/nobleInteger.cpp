int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    for(int i = A.size()-1;i>=0;i--)
    {
        if(A[i] == A.size()-1-i)
        {
            if(i == A.size()-1 || (i < A.size()-1 && A[i+1]!= A[i]))
                return 1;            
        }
    }
    return -1;
}


//after Reset
//Take care of corner cases, like duplicates and -ve numbers
int Solution::solve(vector<int> &A) {
    if(A.size() == 0) return -1;
    sort(A.begin(),A.end());
    if(A[A.size()-1] == 0) return 1;
    for(int i = A.size()-1;i>=0;i--)
    {
        if(i!=A.size()-1 && A[i+1]!=A[i] && A[i] == A.size()-1-i) return 1;
    }
    return -1;
}
