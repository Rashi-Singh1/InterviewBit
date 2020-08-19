string Solution::solve(string A) {
    unordered_map<char, int> m;
    queue<char> q;
    string ans;
    for(auto x : A){
        m[x]++;
        if(m[x] <= 1) q.push(x);
        else while(!q.empty() && m[q.front()] > 1) q.pop();
        if(q.empty()) ans.push_back('#');
        else ans.push_back(q.front());
    }
    return ans;
}
