vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    if(A == 0) return ans;
    ans.push_back(0);
    ans.push_back(1);
    for(int bits = 1; bits < A; bits++){
        for(int i = ans.size()-1; i >= 0 ;i--){
            ans.push_back(ans[i] | (1<<bits));
        }
    }
    return ans;
}