int ans;
void solve(const string A, const string B, int as, int ae, int bs, int be){
    if(ae < as || be < bs || ans == 0 || ae-as != be-bs) return;
    if(ae == as && A[as] == B[bs]) return;
    unordered_map<char, int> am, bm;
    int roota = -1, rootb = -1, front = as, end = be;
    while(front <= ae && end >= bs){        //start matching cluster from start of a and end of b
        if(bm.count(A[front]) > 0) {
            bm[A[front]]--;
            if(bm[A[front]] == 0) bm.erase(A[front]);
        }
        else{
            am[A[front]]++;
        }
        if(am.count(B[end]) > 0) {
            am[B[end]]--;
            if(am[B[end]] == 0) am.erase(B[end]);
        }
        else{
            bm[B[end]]++;
        }
        if(am.size() == 0 && bm.size() == 0 && front != ae) {roota = front; rootb = end;}   //front != ae, it does not consider the full string as cluster
        front++; end--;
    }
    if(roota != -1){    //cluster found 
        solve(A, B, as, roota, rootb, be);
        solve(A, B, roota+1, ae, bs, rootb-1);
    }
    else{               //start matching from start of a and start of a
        roota = -1; rootb = -1;
        bm.clear(); am.clear();
        front = as; end = bs;
        while(front <= ae && end <= be){
            if(bm.count(A[front]) > 0) {
                bm[A[front]]--;
                if(bm[A[front]] == 0) bm.erase(A[front]);
            }
            else{
                am[A[front]]++;
            }
            if(am.count(B[end]) > 0) {
                am[B[end]]--;
                if(am[B[end]] == 0) am.erase(B[end]);
            }
            else{
                bm[B[end]]++;
            }
            if(am.size() == 0 && bm.size() == 0 && front != ae) {roota = front; rootb = end;}
            front++; end++;
        }
        if(roota == -1) ans = 0;        //not found
        else{
            solve(A, B, as, roota, bs, rootb);
            solve(A, B, roota+1, ae, rootb+1, be);
        }
    }
}

int Solution::isScramble(const string A, const string B) {
    if(A.size() != B.size()) return 0;
    ans = 1;
    solve(A, B, 0 , A.size()-1, 0, B.size() -1);
    return ans;
}