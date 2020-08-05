vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans;
    int left = 1;
    int right = B;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == 'I') ans.push_back(left++);
        else ans.push_back(right--);
    }
    ans.push_back(left);
    return ans;
}
