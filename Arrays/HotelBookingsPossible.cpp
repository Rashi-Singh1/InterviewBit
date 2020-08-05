//placement prep
bool Solution::hotel(vector<int> &A, vector<int> &B, int K) {
    int size = A.size();
    if(K == 0) return false;
    if(size == 0) return true;
    vector<pair<int,int> > tim;
    for(int i = 0 ;i < size; i++){
        tim.push_back({A[i],B[i]});
    }
    sort(tim.begin(), tim.end() ,[](pair<int,int>& A, pair<int,int>& B){
        if(A.first == B.first) return A.second < B.second;
        else return A.first < B.first;
    });
    int cur_time = tim[0].first;
    int count = 0;
    map<int,int> finish;
    for(int i = 0; i < size; i++){
        cur_time = tim[i].first;
        if(cur_time == tim[i].first) {
            count++;
            finish[tim[i].second]++;
        }
        while(finish.size() > 0 && finish.begin()->first <= cur_time){
            count-=finish.begin()->second;
            finish.erase(finish.begin()->first);
        }
        if(count > K) return false;
    }    
    return true;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    if(k == 0) return 0;
    if(arrive.size() == 0) return 0;
    multiset<int> going;
    vector<pair<int,int> >blah;
    for(int i = 0;i<arrive.size();i++)
    {
        blah.push_back(make_pair(arrive[i],depart[i]));
    }
    sort(blah.begin(),blah.end());
    for(int i = 0;i<blah.size();i++)
    {
        while(going.size() > 0)
        {
            if(*going.begin() <= blah[i].first) going.erase(*going.begin());
            else break;
        }
        if(blah[i].first == blah[i].second) continue;
        if(going.size() < k) going.insert(blah[i].second);
        else return false;
    }
    return true;
}
