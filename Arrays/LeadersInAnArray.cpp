vector<int> Solution::solve(vector<int> &A) {
    if(A.size() < 2) return A;
    vector<int> sol = {A[A.size()-1]};
    for(int i = A.size() - 2; i >=0; i--){
        if(sol[sol.size()-1] < A[i]) sol.push_back(A[i]);
    }
    return sol;
}
