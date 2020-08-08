typedef long long int ll;

int solve2(vector<int>& A, int B, string C){
    if(B == 0) return 0;
    ll c_len = C.length();
    ll ans = 0;
    int first = (int)(C[c_len-1]-'0');
    int index = 0;
    bool allDone = true;
    for(int i = A.size()-1; i >=0; i--){
        if(A[i] > first) ans+=pow(A.size(),B-1);
        else {
            allDone = false;
            index = i;
            break;
        }
    }
    if(A[index] < first) return (int)ans;                           //the next no would be smaller than C, directly return ans
    else {
        if(allDone) return (int)ans;                                //if min no formed > C, no need to go deeper
        if(B == 1 && first == A[index]) return (int)ans + 1;        //if number formed same as C
        C.pop_back();
        return (int)ans + solve2(A, B-1, C);                        //check for next index
    }
}

int binarySearch(vector<int>& a, int b){
    ll start = 0, end = a.size()-1;
    while(start <= end){
        ll mid = (start + end)/2;
        if(a[mid] == b) return mid;
        else if(a[mid] > b) end--;
        else start++;
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B, int C) {
    if(A.size() == 0 || B == 0) return 0;
    ll c_len = C > 0 ? (ll)log10(C) + 1ll : 0;
    sort(A.begin(), A.end());
    if(B > c_len) return 0;
    ll total = (binarySearch(A,0) == -1 || B == 1) ? pow(A.size(),B) : pow(A.size(),B-1)*(A.size()-1);
    string c_str = to_string(C);
    reverse(c_str.begin(), c_str.end());
    if(B < c_len) return (int)total;
    else {
        int solved = solve2(A,B,c_str);
        return (total-solved < 0) ? 0 : total-solved;
    }
}
