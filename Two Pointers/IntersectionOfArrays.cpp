vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int as = 0, bs = 0;
    vector<int> sol;
    while(as < A.size() && bs < B.size()){
        if(A[as] < B[bs]) as++;
        else if(A[as] > B[bs]) bs++;
        else {
            sol.push_back(A[as]);
            as++;
            bs++;
        }
    }
    return sol;
}


//after reset
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i < A.size() && j < B.size())
    {
        if(A[i] == B[j]) {
            ans.push_back(A[i++]); 
            j++;
        }else if(A[i] > B[j]) j++;
        else i++;
    }
    return ans;
}
