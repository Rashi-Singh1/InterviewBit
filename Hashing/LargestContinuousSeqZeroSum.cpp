typedef long long ll;
vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<ll,int> s;
    vector<int> ans;
    ll sum = 0;
    int start = -1, end = -1;
    for(int i = 0 ; i < A.size(); i++){
        sum += (ll)A[i];
        if(s.count(sum) > 0 || sum == 0){
            if(start == -1 || end-start < i-(s[sum]+1)){
                start = sum == 0 ? 0 : s[sum]+1;
                end = i;
            }
        }
        if(s.count(sum) == 0) s[sum] = i;
    }
    if(start != -1) for(int i = start; i<=end; i++) ans.push_back(A[i]);
    return ans;
}