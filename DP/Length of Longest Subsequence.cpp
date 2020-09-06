//O(N^2) time and O(N) space
//same logic as Longest Increasing Subsequence
int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size() < 2) return (int)A.size();
    vector<int> inc(A.size(), 1), dec(A.size(),1);
    for(int i = 1 ; i < A.size(); i++){
        for(int j = 0 ; j < i; j++){
            if(A[j] < A[i]) inc[i] = max(inc[i], inc[j]+1);
        }
    }
    for(int i = A.size()-1 ; i >= 0; i--){
        for(int j = A.size()-1 ; j > i; j--){
            if(A[j] < A[i]) dec[i] = max(dec[i], dec[j]+1);
        }
    }
    int ans = 1;
    for(int i = 0; i < A.size(); i++){
        ans = max(ans, inc[i]+dec[i]-1);
    }
    return ans;
}

//O(NlogN) time and O(N) space
int Solution::longestSubsequenceLength(const vector<int> &A) {
    vector<int> inc(A.size()), dec(A.size()), temp(A.size());
    int len = 0, ans = 0;
    for(int i = 0 ; i < A.size(); i++){
        int index = lower_bound(temp.begin(), temp.begin()+len, A[i]) - temp.begin();
        inc[i] = index + 1;
        temp[index] = A[i];
        len = max(len, index+1);
    }
    len = 0;
    for(int i = 0 ; i < A.size(); i++) temp[i] = 0;
    for(int i = A.size()-1 ; i >= 0; i--){
        int index = lower_bound(temp.begin(), temp.begin()+len, A[i]) - temp.begin();
        dec[i] = index + 1;
        temp[index] = A[i];
        len = max(len, index+1);
    }
    for(int i = 0 ; i < A.size(); i++){
        ans = max(ans, inc[i] + dec[i] - 1);
    }
    return ans;
}
