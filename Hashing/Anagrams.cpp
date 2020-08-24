vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int> >s;
    vector<vector<int> >ans;
    for(int i = 0 ;i < A.size(); i++){
        string temp = A[i];
        sort(temp.begin(), temp.end());
        s[temp].push_back(i+1);
    }
    for(auto x : s) ans.push_back(x.second);
    return ans;
}