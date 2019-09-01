vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int> > ans;
    if(A.size() < 3) return ans;
    sort(A.begin(),A.end());
    for(int i = 0;i<A.size()-2;i++)
    {
        if (i > 0 && A[i] == A[i-1]) continue;
        int j = i+1;
        int k = A.size()-1;
        while(j < k){
            long long int sum = A[j] + A[k] + A[i];
            if(sum == 0)
            {
                vector<int> temp = {A[i],A[j],A[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && A[j] == A[j-1]) j++;
                while(j<k && A[k] == A[k+1]) k--;
            }
            else if(sum > 0) k--;
            else j++;
        }
    }
    return ans;
}
