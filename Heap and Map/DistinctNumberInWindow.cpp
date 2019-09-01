vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int> Map;
    int start = 0;
    int end = 0;
    vector<int> ans;
    while(end < A.size())
    {
        Map[A[end]]++;
        if(end >= B-1) {
            ans.push_back(Map.size());
            if(Map[A[start]] > 1) Map[A[start]]--;
            else Map.erase(A[start]);
            start++;
        }
        end++;    
    }
    return ans;
}
