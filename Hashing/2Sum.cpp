typedef long long ll;
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> s;
    vector<int> ans;
    for(int i = 0 ; i < A.size(); i++){
        ll diff = (ll)B-(ll)A[i];
        if(s.count((int)diff) > 0) {
            ans.push_back(s[diff]);
            ans.push_back(i+1);
            return ans;
        }
        if(s.count(A[i]) == 0) s[A[i]] = i+1;
    }
    return ans;
}