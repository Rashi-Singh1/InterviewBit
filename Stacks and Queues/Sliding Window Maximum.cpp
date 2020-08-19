vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    deque<int> q;
    for(int i = 0 ; i < min((int)A.size(), B); i++){
        while(!q.empty() && A[q.back()] < A[i]) q.pop_back();
        q.push_back(i);
    }
    if(!q.empty()) ans.push_back(A[q.front()]);
    for(int i = min((int)A.size(), B); i < A.size(); i++){
        while(!q.empty() && q.front() < (i-B+1)) q.pop_front();
        while(!q.empty() && A[q.back()] < A[i]) q.pop_back();
        q.push_back(i);
        if(!q.empty()) ans.push_back(A[q.front()]);
    }
    return ans;
}

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> q, ans;
    for(int i = 0 ; i < min(B, (int)A.size()); i++){
        while(q.size() > 0 && A[q[q.size()-1]] < A[i]) q.pop_back();
        q.push_back(i);
    }
    if(q.size() > 0) ans.push_back(A[q[0]]);
    int index = 0;
    for(int i = index; i < q.size(); i++) if(q[i] < 1) index++;
    for(int i = min(B, (int)A.size()) ; i < A.size() ; i++ ){
        int j = i-B+1;
        if(q[index] < j) index++;
        while(q.size() > index && A[q[q.size()-1]] < A[i]) q.pop_back();
        q.push_back(i);
        ans.push_back(A[q[index]]);
    }
    return ans;
}