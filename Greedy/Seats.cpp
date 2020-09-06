typedef long long ll;
ll mod = 10000003;
int Solution::seats(string A) {
    vector<ll> seat;
    for(int i = 0 ; i < A.size(); i++) if(A[i] == 'x') seat.push_back((ll)i);
    if(seat.size() < 2) return 0;
    ll mid = seat[seat.size()/2], ans = 0ll;
    for(ll i = seat.size()/2-1; i >= 0; i--){
        ans = (ans + ((llabs(seat[i]-seat[i+1])-1ll)%mod)%mod)%mod;
        seat[i] = seat[i+1]-1;
    }
    for(ll i = seat.size()/2+1; i < seat.size(); i++){
        ans = (ans + ((llabs(seat[i]-seat[i-1])-1ll)%mod)%mod)%mod;
        seat[i] = seat[i-1]+1;
    }
    return (int)(ans%mod);
}