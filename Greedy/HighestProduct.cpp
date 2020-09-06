typedef long long ll; 
int Solution::maxp3(vector<int> &A) {
    if(A.size() < 3) return 0;
    sort(A.begin(), A.end());
    ll ans = 0, ans2 = 0, n = A.size();
    ans = (ll)A[n-1]*(ll)A[n-2]*(ll)A[n-3];
    ans2 = (ll)A[0]*(ll)A[1]*(ll)A[n-1]; 
    return (int)max(ans, ans2);
}

typedef long long ll;
int Solution::maxp3(vector<int> &A) {
    if(A.size() < 3) return 0;
    priority_queue<ll> pos, neg;
    priority_queue<ll, vector<ll>, greater<ll> > negneg, pospos;
    for(auto x : A) {
        if(x < 0) {neg.push(llabs((ll)x)); negneg.push(llabs((ll)x));}
        else {pos.push((ll)x); pospos.push((ll)x);}
    }
    bool negi = ((pos.size() == 2 && neg.size() < 2) || pos.size() == 0);     
    if(negi){
        ll ans2, ans; ans2 = ans = negneg.top(); negneg.pop();
        bool allneg = false;
        if(negneg.size() > 1) {
            ans *= negneg.top(); negneg.pop();
            ans *= negneg.top(); negneg.pop();
            allneg = true;
        }
        if(pospos.size() > 1){
            ans2 *= pospos.top(); pospos.pop();
            ans2 *= pospos.top(); pospos.pop(); 
            if(allneg) return (int)max(-1ll*ans, -1ll*ans2);
            return (int)-1ll*ans2;
        }
        return (int)-1ll*ans;
    }
    else{
        ll ans2, ans; ans2 = ans = pos.top(); pos.pop();
        bool allneg = false;
        if(neg.size() > 1) {
            ans *= neg.top(); neg.pop();
            ans *= neg.top(); neg.pop();
            allneg = true;
        }
        if(pos.size() > 1){
            ans2 *= pos.top(); pos.pop();
            ans2 *= pos.top(); pos.pop(); 
            if(allneg) return max(ans, ans2);
            return ans2;
        }
        return (int)ans;
    }
    return 0;
}

//dont miss side conditions like -ve numbers, occurence of 2 neg numbers with +ve large product
int Solution::maxp3(vector<int> &A) {
    map<int, int> sta;
    map<int, int> Min;
    int count = 0;
    int count2 = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(count < 3) {
            sta[A[i]]++;
            count++;
        }
        else{
            if(sta.begin()->first < A[i]) {
                if(sta.begin()->second > 1) sta[sta.begin()->first]--;
                else sta.erase(sta.begin()->first);
                sta[A[i]]++;
            }
        }
        if(count2 < 2)
        {
            Min[A[i]]++;
            count2++;
        }else{
            if(Min.rbegin()->first > A[i]) {
                if(Min.rbegin()->second > 1) Min[Min.rbegin()->first]--;
                else Min.erase(Min.rbegin()->first);
                Min[A[i]]++;
            }
        }
    }
    int ans = 1;
    int ans2 = 1;
    if(count2 == 2){
        ans2*=Min.begin()->first;
        ans2*=Min.rbegin()->first;
        ans2*=sta.rbegin()->first;
    }
    for(auto x : sta) {
        for(int i = 0;i<x.second;i++) ans*=x.first;
    }
    return max(ans,ans2);
}