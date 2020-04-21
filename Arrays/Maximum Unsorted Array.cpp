//placement prep

//O(n) time O(1) space sol
vector<int> Solution::subUnsort(vector<int> &A) {
    int largest = 0, smallest = A.size()-1, s = 1000000, e = -1000000;
    for(int i = 1; i < A.size() ; i++){
        if(A[i] < A[largest]){  
            s = min(s,largest);
            e = max(e,i);
        }
        largest = A[largest] < A[i] ? i : largest;
    }
    for(int i = A.size() - 2; i >= 0; i--){
        if(A[i] > A[smallest]){
            s = min(s,i);
            e = max(e,smallest);
        }
        smallest = A[smallest] > A[i] ? i : smallest;
    }
    if(s == 1000000) {
        vector<int> ans = {-1};
        return ans;
    }
    else{
        vector<int> ans = {s,e};
        return ans;
    }
}
