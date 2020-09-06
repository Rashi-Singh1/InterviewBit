int Solution::solve(vector<vector<int> > &A) {
    if(A.size() < 2) return A.size();
    sort(A.begin(), A.end(), [](vector<int>& A, vector<int>& B){
        return (A[0] < B[0] || (A[0] == B[0] && A[1] <= B[1]));
    });
    int ans = 0;
    priority_queue<int, vector<int>, greater<int> > endTime;
    for(int i = 0; i < A.size(); i++){
        while(!endTime.empty() && endTime.top() <= A[i][0]) endTime.pop();
        endTime.push(A[i][1]);
        ans = max(ans, (int)endTime.size());
    }
    return ans;
}