vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    unordered_map<long long int, vector<vector<int> > > sta;
    vector<vector<int> > ans;
    for(int i = 0;i<A.size();i++)
    {
        for(int j = i+1;j<A.size();j++)
        {
            long long int sum = (long long int)A[i] + (long long int)A[j];
            vector<int> temp = {i,j};
            vector<vector<int > > trash = {temp};
            if(sta.count(sum) == 0) sta.insert(make_pair(sum,trash));
            else sta[sum].push_back(temp);
        }
    }
    for(auto x : sta){
        if(sta.count( (long long int)B - x.first ) != 0)
        {
            auto y = (long long int)B - x.first;
            for(auto z : x.second)
            {
                for(auto t : sta[y])
                {
                    if(t[0] != z[0] && t[1] != z[0] && t[0] != z[1] && t[1] != z[1]  )
                    {
                        vector<int> temp;
                        temp.push_back(A[t[0]]);
                        temp.push_back(A[t[1]]);
                        temp.push_back(A[z[0]]);
                        temp.push_back(A[z[1]]);
                        sort(temp.begin(),temp.end());
                        ans.push_back(temp);
                    }
                }
            }   
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    return ans;
}


