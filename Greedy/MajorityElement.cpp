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
