int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_set<int> sta;
    for(int i = 0;i<A.size();i++)
    {
        if(sta.find(A[i]-B)!= sta.end()) return 1;
        else if(sta.find(B+A[i])!=sta.end()) return 1;
        else sta.insert(A[i]);
    }
    return 0;
}