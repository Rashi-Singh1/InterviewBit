typedef long long int ll;
vector<int> Solution::maxone(vector<int> &A, int B) {
    queue<int> zeroes;
    int start = 0;
    ll s = INT_MAX, e = INT_MIN;
    for(int i= 0 ; i < A.size(); i++){
        if(A[i] == 0){
            zeroes.push(i);
            if(B > 0) B--;
            else{
                if(!zeroes.empty()){
                    int index = zeroes.front();
                    zeroes.pop();
                    start = index+1;
                }
            }
        }
        if(e-s < (ll)((ll)i-(ll)start)){
            e = i;
            s = start;
        }
    }
    vector<int> ans;
    if(s!=INT_MAX && !(s == e && A[s] == 0)){
        for(int i = s; i<=e; i++){
            ans.push_back(i);
        }
    }
    return ans;
}


vector<int> Solution::maxone(vector<int> &A, int B) {
    queue<int> zeroes;
    if(B < 0) B = 0;
    int start = 0;
    int end = 0;
    int count = 0;
    int i = 0;
    int s = 0;int e = 0;
    vector<int> ans;
    while(i<A.size())
    {
        if(A[i] == 0) {
            count++;
            zeroes.push(i);
        }
        if(A[i] == 1 || count <= B) {
            end++;
        }
        else if(count > B)
        {
            start = zeroes.front()+1;
            end = i;
            count--;
            zeroes.pop();
        }
        i++;
        if(end-start > e-s)
        {
           if(A[end] == 0){
                if(end-start-1 > e-s){
                    s = start;
                    e = end-1;
                }
            }
            else{
                s = start;
                e = end;
            }   
        }
    }
    if(end-start > e-s)
    {
        if(A[end] == 0){
            if(end-start-1 > e-s){
                s = start;
                e = end-1;
            }
        }
        else{
            s = start;
            e = end;
        }   
    }
    for(int j = s;j<=e;j++)
        if(j < A.size()) ans.push_back(j);
    return ans;
}
