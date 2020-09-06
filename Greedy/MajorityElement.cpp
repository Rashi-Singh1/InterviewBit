int Solution::majorityElement(const vector<int> &A) {
    int index = 0;
    int count = 1;
    for(int i = 1;i<A.size();i++)
    {
        A[index]==A[i] ? count++ : count--;
        if(count == 0){
            index = i;
            count = 1;
        }
    }
    return A[index];
}

int Solution::majorityElement(const vector<int> &A) {
    if(A.size() == 0) return 0;
    int start = A[0], count = 1;
    for(int i = 1 ; i < A.size(); i++){
        if(count == 0) start = A[i];
        if(A[i] == start) count++;
        else count--;
    }
    count = 0;      //this part not needed as mentioned in the question that majority element would be always be present
    for(auto x : A) if(x == start) count++;
    if(count > (int)(A.size()/2)) return start;
    return 0;
}