
map<long long int, pair<int,queue<pair<int,int> > > > sta;
bool check(long long int sum, int i, int j)
{
    if(sta.count(sum) == 0) return true;
    auto y = sta[sum].second;
    while(!y.empty())
    {
        if(y.front().first == i && y.front().second == j) return false;
        y.pop();
    }
    return true;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    if(A.size() == 0) return A;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<int> ans;
    int count = A.size();
    int i = count-1;
    int j = count-1;
    sta.clear();
    (sta[(long long int)(1ll*A[i] + 1ll*B[j])].first)++;
    sta[(long long int)(1ll*A[i] + 1ll*B[j])].second.push(make_pair(i,j));
    while(sta.size() > 0 && count > 0)
    {
       int temp = sta.rbegin()->first;  //max value
       ans.push_back(temp);
       count--;
        if(sta[temp].first > 1)
        {
            i = sta[temp].second.front().first;
            j = sta[temp].second.front().second;
            (sta[temp].first)--;
            sta[temp].second.pop();
        }
        else{
            i = sta[temp].second.front().first;
            j = sta[temp].second.front().second;
            sta.erase(temp);
        }
        if(i == 0 || j == 0) return ans;
        if(check((long long int)(1ll*A[i-1] + 1ll*B[j]),i-1,j)){
            (sta[(long long int)(1ll*A[i-1] + 1ll*B[j])].first)++;
             sta[(long long int)(1ll*A[i-1] + 1ll*B[j])].second.push(make_pair(i-1,j));
        }
        if( check((long long int)(1ll*A[i] + 1ll*B[j-1]),i,j-1) ){
            sta[(long long int)(1ll*A[i] + 1ll*B[j-1])].second.push(make_pair(i,j-1));
            (sta[(long long int)(1ll*A[i] + 1ll*B[j-1])].first)++;
        }
           
    }
    return ans;
    //94 92 92 91 90 90 89 88 87 86 85 85 84 83 83 83 83 81 81 81 81 79 79 78 77 77 77 77 76 75 75 75 74 74 

}