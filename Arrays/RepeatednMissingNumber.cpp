//For placement - 
typedef long long int ll;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    ll n = A.size();
    ll sum = (ll)((ll)(n*(n+1ll))/(2*1ll));
    ll s_sum = (ll)n*(ll)(n+1ll);
    s_sum*= (ll)((ll)((2*1ll*n) + 1ll)/(6*1ll));
    ll new_sum = 0*1ll, new_s_sum = 0*1ll;
    for(auto x : A){
        new_sum+=(ll)x;
        new_s_sum+=(ll)((ll)x *(ll)x);
    }
    ll r_minus_a = (ll)((ll)new_sum-(ll)sum);
    ll r_add_a = (ll)((ll)(new_s_sum) - (ll)s_sum);
    r_add_a/=(ll)r_minus_a;
    ll repeat = 0*1ll;
    ll absent = 0*1ll;
    repeat = (ll)((ll)r_minus_a + (ll)r_add_a)/(2*1ll);
    absent = (ll)((ll)r_add_a - (ll)r_minus_a)/(2*1ll);
    vector<int> ans = {repeat,absent};
    return ans;
}

typedef long long int ll;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    ll sum = 0;
    ll square = 0;
    ll n = A.size();
    for(int i = 0;i<A.size();i++)
    {
        sum+=(ll)A[i];
        square+=(ll)( (ll)A[i] * (ll)A[i] );
    }
    ll missingMinusRepeating = (ll)( (ll)((ll)( n * (ll)(n + 1ll))/(2ll)) - sum);
    ll missingMinusRepeatingSquare = (ll)( (ll)((ll)( n * (ll)(n + 1ll) * (ll)((ll)(2ll * n) + 1ll) )/(6ll)) - square);
    ll missingPlusRepeating = (ll)(missingMinusRepeatingSquare / missingMinusRepeating);
    vector<int> ans(2);
    
    //repeating
    ans[0] = (ll)((ll)( missingPlusRepeating - missingMinusRepeating ) / (2ll));
    
    //missing
    ans[1] = (ll)((ll)( missingPlusRepeating + missingMinusRepeating ) / (2ll));
    return ans;
}

//

vector<int> Solution::repeatedNumber(const vector<int> &A) {
     long long int sqSumOld = 0, sqSumNew = 0;
     long long int sumOld = 0, sumNew = 0;
    for(int i = 0;i<A.size();i++)
    {
        sqSumNew += ( long long int)((( long long int)A[i]) * (( long long int)A[i]));
        sumNew += ( long long int)A[i];
    }
     long long int size = ( long long int )A.size();
    sqSumOld = ( long long int)((size * (size+1ll) * ((1ll*2*size) + 1ll))/(6*1ll));
    sumOld = ( long long int)((size * (size+1ll))/(2*1ll));
    long long int sum = ((sqSumOld - sqSumNew)/(sumOld-sumNew));
    vector<int> ans;
    ans.push_back((int)((( long long int)sum+(long long int)(sumNew-sumOld))/2));
    ans.push_back((int)((( long long int)sum-(long long int)(sumNew-sumOld))/2));
    return ans;
}


