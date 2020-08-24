typedef double d;
typedef long long ll;
string Solution::fractionToDecimal(int a, int b) {
   ll num = (ll)a, den = (ll)b, ind = 0;
    if(num == 0 || den == 0) return "0";
    d div = (d)num/(d)den;
    if(ceil(div) == floor(div)) return to_string((ll)div);
    bool neg = (div < (d)0);
    if(neg) div = (d)(-1)*div;
    num = llabs(num); den = llabs(den);
    string sign = (neg ? "-" : ""), ans = sign + to_string((ll)(floor(div))) + '.', right;
    num=(num%den)*10;
    unordered_map<ll,ll> s;
    while(num > 0){
        ll quo = num/den;
        ll rem = num%den;
        if(s.count(num) > 0) return ans + right.substr(0, s[num]) + '(' + right.substr(s[num]) + ')';
        right.push_back((char)(quo+'0'));
        s[num] = ind;
        num=rem*10ll;
        ind++;
    }
    return ans + right;
}