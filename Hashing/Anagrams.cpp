vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map< string ,vector<int> > sta;
    for(int i = 0;i<A.size();i++)
    {
        string temp = A[i];
        sort(temp.begin(),temp.end());
        if(sta.find(temp) == sta.end()) {
            vector<int> trash;
            trash.push_back(i+1);
            sta.insert(make_pair(temp,trash));
        }
        else{
            (sta.find(temp)->second).push_back(i+1);
        }
    }
    vector< vector<int> > ans;
    for(auto x : sta)
    {
        ans.push_back(x.second);
    }
    return ans;
}
