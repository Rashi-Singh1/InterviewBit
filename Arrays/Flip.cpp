//For placement
vector<int> Solution::flip(string A) {
    vector<int> sol;
    bool allone = true;
    for(int i = 0; i < A.size();i++){
        if(A[i] == '0') {allone = false; break;}
        else continue;
    }
    if(allone || A.size() == 0) return sol;
    
    int ans = 0;
    int s = 0;
    int e = 0;
    int start = 0;
    int end = 0;
    int cur = 0;
    for(end = 0; end < A.size(); end++){
        if(A[end] == '0') {
            cur++;
            if(ans < cur){
                s = start;
                e = end;
                ans = cur;
            }
            continue;
        }
        else{
            cur--;
        }
        if(cur < 0) {
            start = end + 1;
            cur = 0;
        }
    }
    sol.push_back(s+1);
    sol.push_back(e+1);
    return sol;
}
