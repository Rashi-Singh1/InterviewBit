//dont miss side conditions like -ve numbers, occurence of 2 neg numbers with +ve large product
int Solution::maxp3(vector<int> &A) {
    map<int, int> sta;
    map<int, int> Min;
    int count = 0;
    int count2 = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(count < 3) {
            sta[A[i]]++;
            count++;
        }
        else{
            if(sta.begin()->first < A[i]) {
                if(sta.begin()->second > 1) sta[sta.begin()->first]--;
                else sta.erase(sta.begin()->first);
                sta[A[i]]++;
            }
        }
        if(count2 < 2)
        {
            Min[A[i]]++;
            count2++;
        }else{
            if(Min.rbegin()->first > A[i]) {
                if(Min.rbegin()->second > 1) Min[Min.rbegin()->first]--;
                else Min.erase(Min.rbegin()->first);
                Min[A[i]]++;
            }
        }
    }
    int ans = 1;
    int ans2 = 1;
    if(count2 == 2){
        ans2*=Min.begin()->first;
        ans2*=Min.rbegin()->first;
        ans2*=sta.rbegin()->first;
    }
    for(auto x : sta) {
        for(int i = 0;i<x.second;i++) ans*=x.first;
    }
    return max(ans,ans2);
}
