void solve(const vector<int>& A, int B, long long int start, long long int end, int* left, int* right){
    if(start > end) return; 
    if(A[start] == A[end] && A[start] == B) {
        if(*left == -1) *left = start;
        else *left = min(*left,(int)start);
        if(*right == -1) *right = end;
        else *right = max(*right,(int)end);
        return;
    }
    if(start == end) return;
    long long int mid = (start +  end)/2;
    if(A[mid] == B){
        if(*left == -1) *left = mid;
        else *left = min(*left,(int)mid);
        if(*right == -1) *right = mid;
        else *right = max(*right,(int)mid);
        solve(A,B,start,mid-1,left,right);
        solve(A,B,mid+1,end,left,right);
    }
    else if(A[mid] > B) solve(A,B,start,mid-1,left,right);
    else solve(A,B,mid+1,end,left,right);
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int left = -1, right = -1;
    solve(A,B,0,A.size()-1,&left,&right);
    vector<int> sol = {left,right};
    return sol;
}


vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> ans;
    if(A.size() == 0) return ans;
    int start = 0;
    int x = B;
    int mid;
    int end = A.size()-1;
    int out = -1;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(A[mid] == x) {
            out = mid;
            start = mid+1;
        }
        else if(A[mid] < x) start = mid+1;
        else end = mid-1;
    }
    start = 0;
    end = A.size()-1;
    int in = -1;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(A[mid] == x) {
            in  = mid;
            end = mid-1;
        }
        else if(A[mid] < x) start = mid+1;
        else end = mid-1;
    }
        ans.push_back(in);
        ans.push_back(out);
        return ans;
}
