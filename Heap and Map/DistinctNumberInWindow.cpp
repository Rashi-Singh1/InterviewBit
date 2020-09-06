//way 1: better way
vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int> Map;
    int start = 0;
    int end = 0;
    vector<int> ans;
    while(end < A.size())
    {
        Map[A[end]]++;
        if(end >= B-1) {
            ans.push_back(Map.size());
            if(Map[A[start]] > 1) Map[A[start]]--;
            else Map.erase(A[start]);
            start++;
        }
        end++;    
    }
    return ans;
}

//way 2:
vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int> s;
    vector<int> ans;
    deque<pair<int,int> >q;
    for(int i = 0 ; i < A.size(); i+=1){
        while(!q.empty() && q.front().second < i-B+1) {
            if(s[q.front().first] > 1) s[q.front().first]--;
            else s.erase(q.front().first);
            q.pop_front();
        }
        q.push_back({A[i],i});
        s[A[i]]++;
        if(i >= B-1) ans.push_back(s.size());
    }
    return ans;
}
