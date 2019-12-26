//For placement - 

vector<int> Solution::maxset(vector<int> &A) {
    int start = 0;
    long long int sum = 0;
    long long int ans = A[0];
    int fStart = 0;
    int fEnd = 0;
    vector<int> sol;
    bool allNeg = true;
    for(int i = 0;i<A.size();i++) if(A[i] >=0 ) {allNeg = false; break;}
    if(allNeg) return sol;
    for(int end = 0;end<A.size();end++)
    {
        if(A[end] >= 0){
            sum+=(A[end]*1ll);
        }else {
            sum = 0;
            start = end+1;
        }
        if(sum > ans || (sum == ans && (end - start > fEnd-fStart)))
        {
            ans = sum;
            fStart = start;
            fEnd = end;
        }
    }
    for(int i = fStart;i <= fEnd;i++) sol.push_back(A[i]);
    return sol;
}

//


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

