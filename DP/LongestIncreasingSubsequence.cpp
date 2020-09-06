//O(N^2) time and O(N) space solution
int Solution::lis(const vector<int> &A) {
    if(A.size() < 2) return (int)A.size();
    vector<int> count((int)A.size(),1);
    int ans = 1;
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]) count[i] = max(count[i], count[j]+1);
        }
        ans = max(ans, count[i]);
    }
    return ans;
}

//O(NlogN) time and O(N) space
int Solution::lis(const vector<int>& nums) {
    vector<int> actualSubsequence(nums.size());
    int len = 0;
    for(auto x: nums){
        auto index = lower_bound(actualSubsequence.begin(), actualSubsequence.begin() + len, x) - actualSubsequence.begin();
        actualSubsequence[index] = x;
        len = max(len, (int)index + 1);
    }
    return len;
}

//very good solution:
//Logic for O(NlogN) solution
/*
0 8 4 12 2
len : number of elements filled in actual increasing subsequence

index = lower_bound - __.begin() returns the index where x can be placed, i.e. index-1 is a smaller element than x

if we replace an already present element in actualSub, it won't mean that for ex for actualSub: 0 4 12 and x = 2
actualSub = 0 2 12 won't cause a problem bcs of doubt that 2 occurs after 12
bcs we actually have 4 before 12 for that position
so replacing 4 with 2 in actualSub gave us the chance to have a smaller number for possibility of growing increasing sub

len = max(len, index+1) : if element being replaced inside, ex 4 with 2, then len won't increase
also note, index is 0 based, so actua; size would be max(index+1, len) 
*/