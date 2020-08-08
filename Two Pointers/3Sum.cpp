typedef long long ll;
int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size() < 3) return 0;
    sort(A.begin(), A.end());
    ll sol = INT_MAX;
    for(int i = 0; i < A.size()-2; i++){
        int start = i+1, end = A.size()-1;
        ll sum = INT_MAX;
        while(start < end){
            sum = A[i] + A[start] + A[end];
            if(llabs((ll)B-sum) < llabs((ll)B-sol)) sol = sum;
            if(sum == B) return B;
            else if(sum > B) end--;
            else start++;
        }
    }
    return sol;
}
