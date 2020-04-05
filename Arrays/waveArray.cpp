//For placement - 
vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    if(A.size() < 2) return A;
    for(int i = 0 ;i < A.size() - 1;i+=2){
        int temp = A[i];
        A[i] = A[i+1];
        A[i+1] = temp;
    }
    return A;
}

vector<int> Solution::wave(vector<int> &A) {
    if(A.size() < 2) return A;
    sort(A.begin(),A.end());
    for(int i = 0;i<A.size()-1;i+=2)
    {
        int t = A[i];
        A[i] = A[i+1];
        A[i+1] = t;
    }
    return A;
}

//