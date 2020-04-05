//Forplacement - 
vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> >ans; 
    if(A == 0) return ans;
    vector<int> temp = {1};
    ans.push_back(temp);
    if(A == 1) return ans;
    temp.push_back(1);
    ans.push_back(temp);
    if(A == 2) return ans;
    temp.clear();
    temp.push_back(1);
    for(int i = 2; i < A; i++){
        for(int j = 0; j < ans[i-1].size() - 1;j++){
            temp.push_back(ans[i-1][j] + ans[i-1][j+1]);
        } 
        temp.push_back(1);
        ans.push_back(temp);
        temp.clear();
        temp.push_back(1);
    }
    return ans;
}

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    if(A == 0) return ans;
    
    ans.push_back(vector<int>(1,1));
    if(A == 1) return ans;
    
    ans.push_back(vector<int>(2,1));
    if(A == 2) return ans;
    
    for(int i = 2;i<A;i++)
    {
        vector<int> temp;
        temp.push_back(1);
        for(int j = 0;j<ans[i-1].size()-1;j++)
        {
            temp.push_back(ans[i-1][j] + ans[i-1][j+1]);
        }
        temp.push_back(1);
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int> > Solution::solve(int key) {
    vector<vector<int> >answer;
    vector <int> temp = {1};
    if(key>=1) answer.push_back(temp);
    vector<int> temp2 = {1,1};
    if(key>=2) answer.push_back(temp2);
    for(int i = 2;i<key;i++)
    {
        vector<int> trash;
        trash.push_back(1);
        for(int j = 0;j<answer[i-1].size()-1;j++)
        {
            trash.push_back(answer[i-1][j]+answer[i-1][j+1]);
        }
        trash.push_back(1);
        answer.push_back(trash);
    }
    return answer;
}

//after reset
vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > ans;
    if(A <=0 ) return ans;
    if(A>0)
    {
        vector<int> temp = {1};
        ans.push_back(temp);
    }
    if(A>1)
    {
        vector<int> temp = {1,1};
        ans.push_back(temp);
    }
    if(A >2)
    {
        for(int i = 1;i<A-1;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j = 0;j<ans[i].size()-1;j++)
            {
                temp.push_back(ans[i][j] + ans[i][j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
    }
    return ans;
}

