//O(nLogn) time and O(n) space
int Solution::maximumGap(const vector<int> &A) {
    int size = A.size();
    vector<pair<int,int> > B;
    for(int i = 0 ; i < size ; i++){
        B.push_back(make_pair(A[i],i));
    }
    sort(B.begin(),B.end(),[](pair<int,int>& A, pair<int,int>& B){
        if(A.first == B.first){
            return A.second <= B.second;
        }
        else return A.first < B.first; 
    });
    vector<int> Max(size, INT_MIN);
    for(int i = size - 1 ; i >= 0; i--){
        Max[i] = B[i].second;
        if(i < size - 1) Max[i] = max(Max[i+1],Max[i]);
    }
    int ans = -1;
    for(int i = 0 ; i < size; i++){
        ans = max(ans, Max[i] - B[i].second);
    }
    return ans;
}

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