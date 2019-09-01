int Solution::maximalRectangle(vector<vector<int> > &A) {
    if(A.size() == 0) return 0;
    if(A[0].size() == 0) return 0;
    int row = A.size();
    int col = A[0].size();
    int ans = 0;
    for(int i = 0;i<col;i++)
    {
        for(int j = 1;j<row;j++)
        {
            if(A[j][i] == 0) continue;
            else A[j][i]+=A[j-1][i];
        }
    }
    for(int i = 0;i<row;i++)
    {
        stack<int> sta;
        for(int j = 0;j<col;j++)
        {
            if(sta.empty())
            {
                sta.push(j+1);
            }
            else{
                while(!sta.empty() && A[i][sta.top()-1] > A[i][j])
                {
                    int index = sta.top()-1;
                    sta.pop();
                    int top;
                    if(sta.empty()) {
                        top = 0;
                    }
                    else {
                        top = sta.top();
                    }
                    ans = max(ans,(j-top)*A[i][index]);
                }
                sta.push(j+1);
            }
        }
        while(!sta.empty())
        {
            int index = sta.top()-1;
            sta.pop();
            int top;
            if(sta.empty()) {
                top = 0;
            }
            else {
                top = sta.top();
            }
            ans = max(ans,(col-top)*A[i][index]);
        }
    }
    return ans;
}
