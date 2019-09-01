vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> sta;
    vector<int> ans;
    for(int i = 0;i<A.size();i++)
    {
        if(sta.find(B-A[i]) == sta.end()) sta.insert(make_pair(A[i],i+1));
        else {
            if(ans.size() == 0)
            {
                ans.push_back(min(sta.find(B-A[i])->second,i+1));
                ans.push_back(max(sta.find(B-A[i])->second,i+1));
            }
            else{
                if(ans[1] > max(sta.find(B-A[i])->second,i+1))
                {
                    ans[0] = min(sta.find(B-A[i])->second,i+1);
                    ans[1] = max(sta.find(B-A[i])->second,i+1);
                }
                else if( ans[1] == max(sta.find(B-A[i])->second,i+1) && ans[0] > min(sta.find(B-A[i])->second,i+1))
                {
                    ans[0] = min(sta.find(B-A[i])->second,i+1);
                    ans[1] = max(sta.find(B-A[i])->second,i+1);
                }
            }
        }
    }
    return ans;
}

//even this works, pretty obviously
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> sta;
    vector<int> ans;
    for(int i = 0;i<A.size();i++)
    {
        if(sta.find(B-A[i]) == sta.end()) sta.insert(make_pair(A[i],i+1));
        else {
            ans.push_back(min(sta.find(B-A[i])->second,i+1));
            ans.push_back(max(sta.find(B-A[i])->second,i+1));
            return ans;
        }
    }
    return ans;
}
