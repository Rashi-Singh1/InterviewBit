typedef long double d;
typedef long long ll;
int Solution::maxPoints(vector<int> &x, vector<int> &y) {
    if(x.size() < 3) return (int)x.size();
    unordered_map<d, ll>s;
    ll ans = 2; d slope;
    for(int i = 0 ; i < x.size(); i++){
        for(int j = 0; j < x.size(); j++){
            if(i == j) continue;
            if(x[i] == x[j]) slope = std::numeric_limits<d>::max();
            else slope = (d)((d)y[j]-(d)y[i])/(d)((d)x[j]-(d)x[i]);
            s[slope]++;
            ans = max(ans, (ll)s[slope] + 1);
        }
        s.clear();
    }
    return (int)ans;
}