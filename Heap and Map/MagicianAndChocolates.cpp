//priority_queue solution
typedef long long ll;
ll mod = (ll)pow(10,9)+7ll;
int Solution::nchoc(int A, vector<int> &B) {
    if(B.size() == 0) return 0;
    priority_queue<int> s(B.begin(), B.end());
    ll ans = 0ll;
    while(A){
        ll key = (ll)s.top();
        ans = (ans + key)%mod;
        s.pop();
        s.push((int)(key/2));
        A--;
    }
    return (int)(ans%mod);
}

//giving TLE for map..........nannndddeeee
typedef long long ll;
ll mod = (ll)pow(10,9)+7ll;
int Solution::nchoc(int A, vector<int> &B) {
    if(B.size() == 0) return 0;
    map<int,int> s;
    for(auto x : B) s[x]++;
    ll ans = 0ll;
    while(A && s.size() > 0){
        ll key = (ll)s.rbegin()->first;
        ans = (ans + key)%mod;
        if(s[key] < 2) s.erase(key);
        else s[key]--;
        if(key > 1) s[(int)(key/2)]++;
        A--;
    }
    return (int)(ans%mod);
}