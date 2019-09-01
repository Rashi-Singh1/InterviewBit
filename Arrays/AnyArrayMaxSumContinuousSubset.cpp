
vector<int> Solution::maxset(vector<int> &A) {
    long long localMax = 0, globalMax = 0;
    int startingIndex = 0;
    int endingIndex = 0;
    int s = 0;
    vector<int> ans;
    for(int i = 0;i<A.size();i++)
    {
        localMax+=A[i];
        if(localMax < 0) {
            localMax = 0;
            s = i+1;
        }
        if((localMax > globalMax) || (localMax == globalMax && i-s > endingIndex-startingIndex)) {
            
            globalMax = localMax;
            startingIndex = s;
            endingIndex = i;
        }
    }
    if(startingIndex == 0 && endingIndex == 0 && A[0] < 0)
    {
        
    }
    else
        for(int i = startingIndex;i<=endingIndex;i++)
        {
            ans.push_back(A[i]);
        }
    return ans;
}

