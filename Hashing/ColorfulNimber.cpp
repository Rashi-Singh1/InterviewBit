typedef long long ll;
int Solution::colorful(int num) {
    string A = to_string(num);
    unordered_set<ll> prod;
    for(int i = 0; i < A.size(); i++){
        ll temp = (ll)(A[i]-'0');
        if(prod.count(temp) > 0) return 0;
        prod.insert(temp);
        for(int j = i+1; j < A.size(); j++){
            temp = temp * (ll)(A[j]-'0');
            if(prod.count(temp) > 0) return 0;
            prod.insert(temp);
        }
    }
    return 1;
}
