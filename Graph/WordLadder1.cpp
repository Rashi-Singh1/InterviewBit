bool check(string a, string b)
{
    if(a.size()!=b.size()) return false;
    int count = 0;
    for(int i = 0;i<a.size();i++)
    {
        if(a[i]!=b[i]) count++;
        if(count > 1) return false;
    }
    return true;
}

int Solution::ladderLength(string start, string end, vector<string> &A) {
    unordered_map<string,unordered_set<string> > sta;
    for(int i = 0;i<A.size();i++)
    {
        if(start!=A[i] && check(start,A[i])) {
            sta[start].insert(A[i]);
            sta[A[i]].insert(start);
        }

    }
    for(int i = 0;i<A.size();i++)
    {
         if(end!=A[i]&& check(end,A[i])) {
            sta[end].insert(A[i]);
            sta[A[i]].insert(end);
         }
    }
    for(int i = 0;i<A.size();i++)
    {
        for(int j = 0;j<A.size();j++)
        {
            if(A[i] == A[j]) continue;
            else {
                if(check(A[i],A[j]))
                {
                    sta[A[j]].insert(A[i]);
                    sta[A[i]].insert(A[j]);
                }
            }
        }
    }
    queue<pair<string,int> > q;
    unordered_map<string,bool> s;
    for(auto x : sta) s[x.first] = false;
    int ans = INT_MAX;
    q.push(make_pair(start,0));
    while(!q.empty())
    {
        auto y = q.front();
        q.pop();
        if(y.first == end) return y.second+1;
        if(s[y.first] == false)
        {
            s[y.first] = true;
            for(auto z : sta[y.first])
            {
                if(s[z] == false) q.push(make_pair(z,y.second+1));
            }
        }
    }
    return 0;
}