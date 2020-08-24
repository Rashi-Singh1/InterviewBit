typedef long long int ll;
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    unordered_map<ll, vector<pair<int, int>>> s;
    vector<vector<int> >ans;
    for(int i = 0 ; i < A.size(); i++){
        for(int j = i+1; j < A.size(); j++){
            ll sum = (ll)A[i] + (ll)A[j];
            if(s.count((ll)B-sum) > 0){
                for(auto x : s[(ll)B-sum]){
                    int ind1 = x.first, ind2 = x.second;
                    if(!(ind1 == i || ind1 == j || ind2 == i || ind2 == j)){
                        vector<int> trash = {A[ind1], A[ind2], A[i], A[j]};
                        sort(trash.begin(), trash.end());
                        ans.push_back(trash);
                    }
                }
            }
            s[sum].push_back(make_pair(i,j));
        }
    }
    sort(ans.begin(), ans.end(), [](vector<int>& a, vector<int>& b)->bool{
        return (a[0] < b[0] || (a[0] == b[0] && (a[1] < b[1] || (a[1] == b[1] && (a[2] < b[2] || (a[2] == b[2] && a[3] < b[3]))))));
    });
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    return ans;
}