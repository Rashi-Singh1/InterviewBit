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
