vector<int> Solution::equal(vector<int> &A) {
    unordered_map<long long int, vector<int> > sta;
    vector<int> ans;
    for(int i = 0;i<A.size();i++)
    {
        for(int j = i+1;j<A.size();j++)
        {
            long long int sum = (long long int)((long long int)A[i] + (long long int)A[j]);
            if(sta.count(sum) == 0) {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                sta.insert(make_pair(sum,temp));
            }
            else {
                if(sta[sum][0]!= i && sta[sum][1] != j && sta[sum][0]!=j && sta[sum][1]!=i)
                {
                   if(i < sta[sum][0]) {
                        if(ans.size()!=0)
                        {
                            if(ans[0] > i || (ans[0] == i && ans[1] > j) || (ans[0] == i && ans[1] == j && ans[2] > sta[sum][0]) || (ans[0] == i && ans[1] == j && ans[2] == sta[sum][0] && ans[3] > sta[sum][1]) )
                            {
                                ans[0] = i;
                                ans[1] = j;
                                ans[2] = sta[sum][0];
                                ans[3] = sta[sum][1];
                            }
                        }
                        else {
                            ans.push_back(i);
                            ans.push_back(j);
                            ans.push_back(sta[sum][0]);
                            ans.push_back(sta[sum][1]);
                        }
                       
                    }
                    else{
                        if(ans.size()!=0)
                        {
                            if(ans[0] > sta[sum][0] || (ans[0] == sta[sum][0] && ans[1] > sta[sum][1]) || (ans[0] == sta[sum][0] && ans[1] == sta[sum][1] && ans[2] > i) || (ans[0] == sta[sum][0] && ans[1] == sta[sum][1] && ans[2] == i && ans[3] > j) )
                            {
                                ans[0] = sta[sum][0];
                                ans[1] = sta[sum][1];
                                ans[2] = i;
                                ans[3] = j;
                            }
                        }
                        else{
                            ans.push_back(sta[sum][0]);
                            ans.push_back(sta[sum][1]);
                            ans.push_back(i);
                            ans.push_back(j);
                        }
                    }
                    
                }
            }
        }
    }
    return ans;
}
