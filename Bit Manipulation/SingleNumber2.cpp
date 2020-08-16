int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    for(int i = 0 ; i < 32; i++){
        int count = 0, mask = (1<<i);
        for(auto x : A){
            if(!((x&mask) == 0)) count++;
        }
        if(count%3 == 1) ans|=mask;
    }
    return ans;
}
