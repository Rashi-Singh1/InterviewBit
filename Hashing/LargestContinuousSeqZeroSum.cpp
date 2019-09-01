vector<int> Solution::lszero(vector<int> &A) {
    if(A.size() == 0) return A;
    int s = -1;
    int e = -1;
    multimap<long long int, int> sta;
    sta.insert(make_pair((long long int)A[0],0));
    long long int sum = A[0];
    for(int i = 1;i<A.size();i++)
    {
        sum+=(long long int)A[i];
        sta.insert( make_pair( sum,i ) );
    }
    auto start = sta.begin();
    auto end = sta.begin();
    // for(auto x : sta)
    // {
    //     cout<<x.first<<" "<<x.second<<endl;
    // }cout<<endl;
    for(end = sta.begin();end!=sta.end();end++)
    {
        // cout<<s<<" "<<e<<endl;
        if(end->first == start->first)
        {
            if(e-s < end->second - start->second || (e-s == end->second - start->second && start->second < s))
            {
                e  = end->second;
                s = start->second;
            }
        }
        else start = end;
    }
    if(end!=sta.end() && end->first == start->first)
    {
        if(e-s < end->second - start->second)
        {
            e  = end->second;
            s = start->second;
        }
    }
    bool flag = false;
    for(end = sta.begin();end!=sta.end();end++)
    {
        // cout<<s<<" "<<e<<endl;
        if(end->first == 0)
        {
            if(flag == false && (e-s < end->second+1 || (e-s == end->second+1 && s >= 0)) )
            {
                e  = end->second;
                s = 0;
                flag = true;
            }
            else{
                if(e-s < end->second)
                {
                    e  = end->second;
                    s = 0;
                }
            }
        }
    }
    vector<int> ans;
    if(s == -1) return ans;
    if(flag == false)
        for(int i = s+1;i<=e;i++)
        {
            ans.push_back(A[i]);
        }
    else
        for(int i = 0;i<=e;i++)
        {
            ans.push_back(A[i]);
        }
    return ans;
}
