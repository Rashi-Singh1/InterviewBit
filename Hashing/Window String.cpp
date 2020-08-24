bool isdone(unordered_map<char, int>& m, unordered_map<char, int>& wind){
    for(auto x : m){
        if(x.second > wind[x.first]) return false;
    }
    return true;
}

string Solution::minWindow(string A, string B) {
    unordered_map<char, int> m, wind;
    for(auto x : B) m[x]++;
    deque<pair<char, int> > q;
    int start = -1, s = -1, e = -1;
    for(int i = 0 ; i < A.size(); i++){
        if(m.count(A[i]) > 0){
            wind[A[i]]++;
            q.push_back({A[i], i});
            if(wind[A[i]] > m[A[i]]){
                while(!q.empty()){
                    char trash = q.front().first;
                    if(m[trash] >= wind[trash]) break;
                    wind[trash]--;
                    q.pop_front();
                }
                start = (q.empty() ? i : q.front().second);
            }
            if(isdone(m,wind) && (e-s > i-start || e == -1)) {s = start; e = i;}
        }
    }
    if(s == -1) return "";
    return A.substr(s, e-s+1);
}