typedef long long ll;
ll mod = 10003;
int Solution::solve(string A) {
    ll ans = 0;
    unordered_set<char> vowel = {'a','e','i','o','u','A','E','I','O','U'};
    for(int i = 0 ; i < A.size(); i++){
        if(vowel.count(A[i]) != 0) ans = ((ll)ans + ((ll)A.size()-(ll)i)%mod)%mod;
    }
    return (int)ans%mod;
}

int Solution::solve(string A) {
    long long int sum = 0;
    transform(A.begin(), A.end(), A.begin(), ::tolower); 
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
        {
            sum  = (sum + (A.size()-i)%10003)%10003;
        }
    }
    return sum%10003;
}
