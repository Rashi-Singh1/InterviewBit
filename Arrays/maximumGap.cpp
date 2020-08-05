//placement prep
int find_index(int x, int Min, int gap){
    return (x-Min)/gap;
}
int Solution::maximumGap(const vector<int> &A) {
    int size = A.size();
    if(size < 2) return 0;
    int Min = INT_MAX, Max = INT_MIN;
    for(auto x : A){
        Min = min(Min,x);
        Max = max(Max,x);
    }
    if(Min == Max) return 0;
    int gap = (Max-Min)/(size - 1);
    if(gap == 0) return Max-Min;
    vector<pair<int,int> > buckets( size + ((Max-Min)%(size-1)), make_pair(INT_MAX,-1));
    for(auto x : A){
        int index = find_index(x,Min,gap);
        int cur_min = buckets[index].first;
        int cur_max = buckets[index].second;
        buckets[index].first = min(cur_min, x);
        buckets[index].second = max(cur_max, x);
    }
    int start = -1, idx = 0;
    while(idx < buckets.size()){
        if(buckets[idx].second != -1) {
            start = idx;
            break;
        }
        idx++;
    }
    if(start == -1) return 0;
    int ans = gap;
    int temp = buckets[start].second;
    for(int i = start;i < buckets.size(); i++){
        if(buckets[i].second == -1) continue;
        else{
            ans = max(ans,buckets[i].second - buckets[i].first);
            ans = max(ans, buckets[i].first - temp);
            temp = buckets[i].second;
        }
    }
    return ans;
}

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

/*
Any form of sorting is going to be atleast O(n * log n), so we need to think outside of sorting. Now, first try to think if you were already given the minimum value MIN and maximum value MAX in the array of size N, under what circumstances would the max gap be minimum and maximum ?
Obviously, maximum gap will be maximum when all elements are either MIN or MAX making maxgap = MAX - MIN.
Maximum gap will be minimum when all the elements are equally spaced apart between MIN and MAX. Lets say the spacing between them is gap.
So, they are arranged as MIN, MIN + gap, MIN + 2gap, MIN + 3gap, … MIN + (N-1)*gap
where MIN + (N-1)*gap = MAX => gap = (MAX - MIN) / (N - 1).

So, we know now that our answer will lie in the range [gap, MAX - MIN].
Now, if we know the answer is more than gap, what we do is create buckets of size gap for ranges [MIN, MIN + gap), [Min + gap, MIN + 2* gap) … and so on. There will only be (N-1) such buckets. We place the numbers in these buckets based on their value.
If you pick any 2 numbers from a single bucket, their difference will be less than gap, and hence they would never contribute to maxgap ( Remember maxgap >= gap ). We only need to store the largest number and the smallest number in each bucket, and we only look at the numbers across bucket.

Now, we just need to go through the bucket sequentially ( they are already sorted by value ), and get the difference of min_value with max_value of previous bucket with atleast one value. We take maximum of all such values.
*/