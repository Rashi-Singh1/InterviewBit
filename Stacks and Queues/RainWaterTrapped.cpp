//best solution
//two pointer sol, O(N) time and O(1) space
int Solution::trap(const vector<int> &A) {
    int start = 0, end = A.size()-1, ans = 0, lmax = INT_MIN, rmax = INT_MIN;
    while(start < end){
        lmax = max(lmax, A[start]);
        rmax = max(rmax, A[end]);
        if(lmax <= rmax) ans+=(lmax-A[start++]);
        else ans+=(rmax-A[end--]);
    }
    return ans;
}

//solution using stack as asked in the question
//O(N) space and time
int Solution::trap(const vector<int> &A) {
    stack<int> ind;
    for(int i = 0 ; i < A.size(); i++){
        if(ind.empty()) ind.push(i);
        else {
            if(A[ind.top()] <= A[i]) ind.push(i);
        }
    }
    int temp = -1, start = temp;
    if(!ind.empty()){
        start = temp = ind.top();
        ind.pop();
    }
    int ans = 0;
    while(!ind.empty()){
        int prev = ind.top();
        ind.pop();
        int base = min(A[prev], A[temp]);
        for(int i = prev + 1; i < temp ; i++){
            ans+=(base-A[i]);
        }
        temp = prev;
    }                                               //till here find solution such that there is a larger wall on the right
    int end = (start == -1) ? 0 : start;
    for(int i = A.size()-1; i >= start; i--){
        if(ind.empty()) ind.push(i);
        else {
            if(A[ind.top()] <= A[i]) ind.push(i);
        }
    }
    if(!ind.empty()){
        temp = ind.top();
        ind.pop();
    }
    while(!ind.empty()){
        int prev = ind.top();
        ind.pop();
        int base = min(A[prev], A[temp]);
        for(int i = temp  + 1; i < prev ; i++){
            
            ans+=(base-A[i]);
        }
        temp = prev;
    }                                               //till here find solution if larger wall on the left (continued, after the max right wall, if it exists)
    return ans;
}


int Solution::trap(const vector<int> &A) {
    vector<int> right(A.size(),-1);
    int lMax = -1;
    for(int i = A.size()-1;i>=0;i--)
    {
        if(lMax == -1) {
            right[i] = lMax;
            lMax = A[i];
        }
        else{
            if(lMax >= A[i]) right[i] = lMax;
            else {
                right[i] = -1;
                lMax = A[i];
            }
        }
    }
    lMax = -1;
    long long int ans = 0;
    for(int i = 0;i<A.size();i++)
    {
        if(lMax>=A[i] && right[i]!=-1) ans+=(min(lMax,right[i])-A[i]);
        else lMax = A[i];
    }
    return (int)ans;
}
