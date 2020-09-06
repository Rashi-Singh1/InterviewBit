typedef long long ll;
ll mod = 1000000007;
int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0 || A[0].size() == 0) return 0;
    ll col = (ll)A[0].size(), row = (ll)A.size(), ans = 0ll; 
    for(ll r = 1 ; r < row; r++){
        for(ll c = 0 ; c < col; c++){
            A[r][c] = ((A[r-1][c] * A[r][c])%mod + A[r][c])%mod;
        }
        sort(A[r-1].begin(), A[r-1].end());
        ll start = 0, end = col-1ll;
        while(start <= end){
            ans = max(ans, (end-start+1ll)*(ll)A[r-1][start]);
            start++;
        }
    }
    sort(A[row-1].begin(), A[row-1].end());
    ll start = 0, end = col-1ll;
    while(start <= end){
        ans = max(ans, (end-start+1ll)*(ll)A[row-1][start]);
        start++;
    }
    return ans;
}