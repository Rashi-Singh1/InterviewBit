//O(DlogD) time and O(D) space solution
vector<int> Solution::solve(int A, int B, int C, int D) {
    set<int> heap;
    heap.insert(A);
    heap.insert(B);
    heap.insert(C);
    vector<int> ans;
    while(D > 0){
        int smol = *(heap.begin());
        heap.erase(smol);
        ans.push_back(smol);
        heap.insert(smol * A);
        heap.insert(smol * B);
        heap.insert(smol * C);
        D--;
    }
    return ans;
}

//way 2:
//O(D) solution
//We store the smallest number that hasn't been multiplied with the given prime numbers
vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> ans;
    int val[3] = {A, B, C};
    int ind[3] = {-1, -1, -1};
    while(D > 0){
        D--;
        int minn = INT_MAX;
        for(int i = 0 ; i < 3; i++){
            if(ans.size() > ind[i] && ind[i] >= 0) minn = min(minn, val[i]*ans[ind[i]]);
            else minn = min(minn, val[i]);
        }
        ans.push_back(minn);
        for(int i = 0 ; i < 3; i++){
            if(ans.size() > ind[i] && ind[i]!=-1 && minn == val[i]*ans[ind[i]]) ind[i]++;
            else if(minn == val[i]) ind[i] = 0;
        }
    }
    return ans;
}
