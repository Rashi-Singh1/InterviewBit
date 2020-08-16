void getPrefixSuffix(const string sub, vector<int>& LSA){
    int i = 0;
    for(int j = 1; j < sub.size(); j++){
        if(sub[i] == sub[j]){
            LSA[j] = i + 1;
            i++;
        }
        else{
            if(i == 0) LSA[j] = 0;
            else{
                i = LSA[i-1];
                j--;
            }
        }
    }
}
 
int subset(const string sup, const string sub){
    if(sub.size() > sup.size()) return -1;
    if(sub.size() == 0) return -1;
 
    vector<int> LSA(sub.size(),0);
    getPrefixSuffix(sub, LSA);
    
    int supIdx = 0, subIdx = 0;
    for(supIdx = 0; supIdx < sup.size(); supIdx++){
        if(subIdx == sub.size()) return supIdx-subIdx;
        if(sup[supIdx] == sub[subIdx]) subIdx++;
        else{
            if(subIdx != 0){
                subIdx = LSA[subIdx - 1];
                supIdx--;
            } 
        }
    }
    if(subIdx == sub.size()) return supIdx-subIdx;
    return -1;
    
}

//KMP algo for O(n) time complexity
//check rabin karp for ease of implementation
int Solution::strStr(const string A, const string sub) {
    return subset(A,sub);
}





//brute force : O(m*n)
int Solution::strStr(const string A, const string B) {
    if(A.size() == 0 && B.size() == 0) return 0;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == B[0])
        {
            int k = i+1;
            bool flag = false;
            for(int j = 1;j<B.size();j++)
            {
                if(A[k]!=B[j]) {
                    flag = true;
                    break;
                }
                else k++;
            }
            if(flag == false) return i;
        }
    }
    return -1;
}

