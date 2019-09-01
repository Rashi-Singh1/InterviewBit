vector<int> Solution::repeatedNumber(const vector<int> &A) {
     long long int sqSumOld = 0, sqSumNew = 0;
     long long int sumOld = 0, sumNew = 0;
    for(int i = 0;i<A.size();i++)
    {
        sqSumNew += ( long long int)((( long long int)A[i]) * (( long long int)A[i]));
        sumNew += ( long long int)A[i];
    }
     long long int size = ( long long int )A.size();
    sqSumOld = ( long long int)((size * (size+1ll) * ((1ll*2*size) + 1ll))/(6*1ll));
    sumOld = ( long long int)((size * (size+1ll))/(2*1ll));
    long long int sum = ((sqSumOld - sqSumNew)/(sumOld-sumNew));
    vector<int> ans;
    ans.push_back((int)((( long long int)sum+(long long int)(sumNew-sumOld))/2));
    ans.push_back((int)((( long long int)sum-(long long int)(sumNew-sumOld))/2));
    return ans;
}