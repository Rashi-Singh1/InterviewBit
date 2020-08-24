typedef long long ll;
vector<int> Solution::equal(vector<int> &A) {
    unordered_map<ll, pair<int,int>>s;
    int a1 = -1, a2 = -1, a3 = -1, a4 = -1;
    for(int i = 0 ; i < A.size(); i++){
        for(int j = i + 1; j < A.size(); j++){
            ll sum = (ll)A[i] + (ll)A[j];
            if(s.count(sum) == 0) s[sum] = make_pair(i,j);
            else{
                auto x = s[sum];
                if(i!=x.first && j!=x.first && i!=x.second && j!=x.second){
                    if(a1 == -1 || a1 > x.first || (a1 == x.first && (a2 > x.second || (a2 == x.second && (a3 > i || (a3 == i && a4 > j)))))){
                        a1 = x.first;
                        a2 = x.second;
                        a3 = i;
                        a4 = j;
                    }
                }
            }
        }
    }
    if(a1 != -1){
        vector<int> ans = {a1,a2,a3,a4};
        return ans;
    }
    vector<int> ans;
    return ans;
}