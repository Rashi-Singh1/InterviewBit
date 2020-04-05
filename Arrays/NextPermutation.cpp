//For placements - 

vector<int> Solution::nextPermutation(vector<int> &A) {
    for(int i = A.size()-1;i>0;i--)
    {
        if(A[i] > A[i-1])
        {
            for(int j = A.size()-1;j >=i;j--)
            {
                if(A[j] > A[i-1])
                {
                    int t = A[i-1];
                    A[i-1] = A[j];
                    A[j] = t;
                    sort(A.begin()+i,A.end());
                    return A;
                }
            }
        }
    }
    reverse(A.begin(),A.end());
    return A;
}

//


void Solution::nextPermutation(vector<int> &A) {
    if(A.size() <= 1) return;
    bool done = false;
    for(int i = A.size()-1;i > 0;i--)
    {
        if(A[i] > A[i-1]) {
            done = true;            
            for(int j = A.size()-1;j>i-1;j--)
            {
                if(A[j] > A[i-1])
                {
                    int t = A[j];
                    A[j] = A[i-1];
                    A[i-1] = t;
                    break;
                }
            }
            reverse(A.begin()+i,A.end());
            return;
        }
    }
    if(done == false) reverse(A.begin(),A.end());
}
