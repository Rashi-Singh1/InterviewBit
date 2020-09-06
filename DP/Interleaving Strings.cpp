
int Solution::isInterleave(string A, string B, string C) {
    if(A.size() == 0) return (B == C ? 1 : 0);
    if(B.size() == 0) return (A == C ? 1 : 0);
    if(C.size() != A.size() + B.size()) return 0;
    vector<int> a(C.size()+1), b(C.size()+1);
    int i = 1, k = 0;
    a[i] = b[i] = 0;
    while(i < a.size() && i >= 0){
        if(k == C.size()) return 1;
        if(a[i-1] < A.size() && A[a[i-1]] == C[k]){
            if(b[i-1] < B.size() && B[b[i-1]] == C[k]){ //both not completed and equal to c[k]
                a[i] = a[i-1]+1;
                b[i] = b[i-1]+1; 
                i++; k++;
            }
            else{   //a not complete and equal, b may be unequal or complete
                int temp = i-1;
                while(temp > 0){
                    if(b[temp] == b[temp-1]+1 && a[temp] == a[temp-1]+1) temp--;
                    else break;
                }
                for(int o = temp+1; o <= i; o++) b[o] = b[o-1];
                if(temp == i-1){
                    a[i] = a[i-1]+1;
                    b[i] = b[i-1]; 
                    i++; k++;
                }
            }
        }
        else{
            if(b[i-1] < B.size() && B[b[i-1]] == C[k]){ //b not complete and equal and a may be complete or unequal
                int temp = i-1;
                while(temp > 0){
                    if(b[temp] == b[temp-1]+1 && a[temp] == a[temp-1]+1) temp--;
                    else break;
                }
                for(int o = temp+1; o <= i; o++) a[o] = a[o-1];
                if(temp == i-1){
                    a[i] = a[i-1];   
                    b[i] = b[i-1]+1;
                    i++; k++;
                }
            }
            else{   //complete or not equal
                int temp = i-1;
                while(temp > 0){
                    if(b[temp] == b[temp-1]+1 && a[temp] == a[temp-1]+1) temp--;
                    else break;
                }
                for(int o = temp+1; o <= i; o++) a[o] = a[o-1];
                if(temp == i-1) return 0;
                if(A[a[i-1]] != C[k] && B[b[i-1]] != C[k]) return 0;
            }
        }
    }
    return 1;
}