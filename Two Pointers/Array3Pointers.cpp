typedef long long ll;
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int as = 0, bs = 0, cs = 0;
    ll ans = INT_MAX, temp;
    while(as < A.size() && bs < B.size() && cs < C.size()){
        temp = max(llabs((ll)((ll)A[as]-(ll)B[bs])),llabs((ll)((ll)A[as]-(ll)C[cs])));
        temp = max(temp,llabs((ll)((ll)C[cs]-(ll)B[bs])));
        ans = min(ans,temp);
        if(A[as] < B[bs]){
            if(C[cs] < A[as]) cs++;
            else as++;
        }else{
            if(C[cs] < B[bs]) cs++;
            else bs++;
        }
    }
    return ans;
}

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0;
    int j = 0;
    int k = 0;
    int ans = INT_MAX;
    while(i<A.size() && j<B.size() && k < C.size())
    {
        int temp = max(A[i],B[j]);
        temp = max(temp,C[k]);
        int temp2 = min(A[i],B[j]);
        temp2 = min(temp2,C[k]);
        ans = min(ans,temp-temp2);
        if(temp2 == A[i]) i++;
        else if(temp2 == B[j]) j++;
        else k++;
    }
    return ans;
}
