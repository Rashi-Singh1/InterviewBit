int Solution::maximumGap(const vector<int> &A) {
    if(A.size() < 2) return 0;
    int Min = A[0];
    int Max = A[0];
    for(int i = 1; i < A.size() ; i++)
    {
        Max = max (Max, A[i]);
        Min = min (Min, A[i]);
    }
    int n = A.size();
    int gap = (Max - Min)/(n - 1);
    
    if(gap == 0) return Max-Min;
    
    vector<pair<int,int> > buckets (n+1,make_pair(INT_MAX,INT_MIN));
    for(int i = 0 ; i < n ; i++ )
    {
        int curMin = buckets[(A[i] - Min)/gap].first;
        int curMax = buckets[(A[i] - Min)/gap].second;
        buckets[(A[i] - Min)/gap].first = min(curMin,A[i]);
        buckets[(A[i] - Min)/gap].second = max(curMax,A[i]);
    }
    
    int ans = gap;
    int start = INT_MAX;
    int end = INT_MIN;
    int nextStart = INT_MAX;
    int startingIndex = -1;
    for(int i = 0;i < buckets.size() -1 ;i++ )
    {
        if(buckets[i].first == INT_MAX) continue;
        else {
            startingIndex = i;
            break;
        }
    }
    if(startingIndex != -1) start = buckets[startingIndex].second;
    for(int i = startingIndex + 1 ;i < buckets.size();i++)
    {
        if(buckets[i].first == INT_MAX) continue;
        else{
            end = buckets[i].first;
            nextStart = buckets[i].second;
            ans = max(ans,end-start);
            start = nextStart;
        }
    }
    return ans;
    
}