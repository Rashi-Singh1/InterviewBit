bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    if(k == 0) return 0;
    if(arrive.size() == 0) return 0;
    multiset<int> going;
    vector<pair<int,int> >blah;
    for(int i = 0;i<arrive.size();i++)
    {
        blah.push_back(make_pair(arrive[i],depart[i]));
    }
    sort(blah.begin(),blah.end());
    for(int i = 0;i<blah.size();i++)
    {
        while(going.size() > 0)
        {
            if(*going.begin() <= blah[i].first) going.erase(*going.begin());
            else break;
        }
        if(blah[i].first == blah[i].second) continue;
        if(going.size() < k) going.insert(blah[i].second);
        else return false;
    }
    return true;
}
