int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() < 2) return A.size();
    int start = 1, trash = A[0];
    for(int i = 1 ; i < A.size(); i++){
        if(A[i] == trash) continue;
        else {
            trash = A[i];
            A[start++] = A[i];
        }
    }
    A.erase(A.begin()+start, A.end());
    return start;
}


int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() < 2) return A.size();
    int cur = 0;
    int next = 1;
    bool repeat = false;
    for(;next < A.size(); next++){
        if(A[cur] == A[next]){
            if(repeat == false) {
                repeat = true;
            }
        }
        else{
            cur++;
            A[cur] = A[next];
            repeat = false;
        }
    }
    A.resize(distance(A.begin(), A.begin() + cur+1));
    return cur+1;
}