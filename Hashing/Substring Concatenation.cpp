//way 1
typedef long long ll;
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> ans;
    if(B.size() == 0 || A.size() == 0 || B[0].size() == 0) return ans;
    unordered_map<string, int> s;
    for(auto x : B) s[x]++;
    ll subs = (ll)B[0].size(), bs = B.size(), ws = bs*subs;
    for(int i = 0 ; i < A.size(); i++){
        unordered_map<string, int> window;
        for(int j = i ; j < min(i + (int)ws, (int)A.size()) ; j += subs){
            string temp = A.substr(j,subs);
            window[temp]++;
        }
        bool add = true;
        for(auto x : s){
            if(window[x.first] != x.second) {
                add = false;
                break;
            }
        }
        if(add) ans.push_back(i);
    }
    return ans;
}

//way 2
typedef long long ll;
void cal(const vector<string>& B, vector<vector<int> >& lps){
    for(int bi = 0 ; bi < B.size(); bi++){
        int i = 0;
        for(int j = 1; j < B[0].size(); j++){
            if(B[bi][i] == B[bi][j]) lps[bi][j] = ++i;
            else{
                if(i == 0) lps[bi][j] = 0;
                else {
                    i = lps[bi][i-1];
                    j--;
                }
            }
        }        
    }
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> ans;
    if(A.size() == 0 || B.size() == 0) return ans;
    ll subs = (ll)B[0].size(), sups = (ll)A.size();
    ll ws = (ll)B.size()*subs;
    vector<int> trash(subs,0);
    vector<vector<int> >lps((int)B.size(),trash);
    vector<unordered_set<int> >ind((int)B.size());
    cal(B,lps);
    for(ll bi = 0 ; bi <B.size() ;bi++){
        ll i = 0;
        for(ll j = 0 ; j < sups; j++){
            if(i == subs) {
                ind[bi].insert(j-subs);
                i = lps[bi][i-1];
            }
            if(A[j] == B[bi][i]) i++;
            else{
                if(i > 0) {
                    i = lps[bi][i-1];
                    j--;
                }
            }
        }
        if(i == subs){
            ind[bi].insert(A.size()-subs);
        }
    }
    string actual(B.size(),'1');
    for(ll i = 0 ; i <= sups-ws; i++){        //i<->i+ws
        string done(B.size(),'0');
        string subdone(B.size(),'0');
        for(ll j = i ; j < i+ws; j+=subs){
            for(int bi = 0; bi < B.size(); bi++){
                if(ind[bi].count(j) > 0 && subdone[bi] == '0') {
                    done[(j-i)/subs] = '1';
                    subdone[bi] = '1';
                    break;
                }
            }
        }
        if(done==actual) ans.push_back(i);
    }
    return ans;
}