int Solution::exist(vector<string> &A, string B) {
    if(B.size() == 0) return 1;
    for(int i = 0;i<A.size();i++)
    {
        for(int j= 0 ;j<A[i].size();j++){
            int index = 0;
            if(A[i].size() > 0 && A[i][j] == B[0]){
                stack<pair<int,int> > sta;
                stack<int> matched;
                sta.push(make_pair(i,j) );
                while(!sta.empty())
                {
                    pair<int,int> cur = sta.top();
                    // cout<<A[cur.first][cur.second]<<" ";
                    sta.pop();
                    if(A[cur.first][cur.second] == B[index])
                    {
                        matched.push(index);
                        index++;
                        if(index == B.size()) return 1;
                        bool nextMatch = false;
                        if(cur.first > 0)
                        {
                            if(A[cur.first - 1][cur.second] == B[index])
                            {
                                sta.push(make_pair(cur.first-1,cur.second));
                                nextMatch = true;
                            }
                        }
                        if(cur.second > 0)
                        {
                            if(A[cur.first][cur.second-1] == B[index])
                            {
                                sta.push(make_pair(cur.first,cur.second-1));
                                nextMatch = true;                            
                            }
                        }
                        if(cur.first+1 < A.size())
                        {
                            if(A[cur.first+1][cur.second] == B[index])
                            {
                                sta.push(make_pair(cur.first+1,cur.second));
                                nextMatch = true;                           
                            }
                        }
                        if(cur.second+1 < A[cur.first].size())
                        {
                            if(A[cur.first][cur.second+1] == B[index])
                            {
                                sta.push(make_pair(cur.first,cur.second+1));
                                nextMatch = true;
                            }
                        }
                        if(nextMatch == false){
                            if(!matched.empty()) {
                                index = matched.top();
                                matched.pop();
                            }
                            else return 0;
                        }
                    }
                    else{
                        if(!matched.empty()) {
                            index = matched.top();
                            matched.pop();
                        }
                        else return 0;
                    }
                    
                }
            }
        }
    }
    // cout<<endl;
    return 0;
}
