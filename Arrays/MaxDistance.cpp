int Solution::maximumGap(const vector<int> &A) {
    if(A.size() < 2) return A.size()-1;
    int ans = 0;
    vector<int> Min = {A[0]};
    vector<int> Max = {A[A.size()-1]};
    for(int i = 1;i<A.size();i++) {
        Min.push_back(min(A[i],Min[i-1]));
    }
    int k =1;
    for(int i = A.size()-2;i>=0;i--,k++) {
        Max.push_back(max(A[i],Max[k-1]));
    }
    reverse(Max.begin(),Max.end());
    int i = 0;
    int j = 0;
    while(i < A.size() && j <A.size())
    {
        if(Max[j] >= Min[i]) {
            ans = max(ans,j-i);
            j++;
        }
        else i++;
    }
    return ans;
}