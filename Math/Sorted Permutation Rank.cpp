typedef long long int ll;
long long int mod = 1000003;

ll binarySearch(char a, string B){
    ll start = 0;
    ll end = B.size()-1;
    ll ans = -1;
    while(start <= end){
        ll mid = (((start +  end)%mod)/2ll)%mod;
        if(B[mid] == a) return mid%mod;
        else if(B[mid] > a) end--;
        else start++;
    }
    return ans%mod;
}

//can memoize fact
ll fact(ll a){
    ll ans = a%mod;
    for(ll i = 1; i < a; i++){
        ans = (ans*(i%mod))%mod;
    }
    return ans;
}

//O(n^2) time worst??
int Solution::findRank(string A) {
    if(A.size() < 2) return 1;
    string B = A;
    sort(B.begin(), B.end());
    ll ans = 0;
    for(ll i = 0 ; i < A.size(); i++){
        ll index = binarySearch(A[i],B);
        ans= (ans + (fact(B.size()-1ll)*index)%mod)%mod;
        if(index < B.size()) B.erase(B.begin()+index);
    }
    return (ans+1)%mod;
}