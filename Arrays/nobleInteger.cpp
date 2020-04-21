//for placement - 

//O(nlogn) time and O(1) space sol
int Solution::solve(vector<int> &A) {
    if(A.size() == 0) return -1;
    sort(A.begin(), A.end());
    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] == A.size() - i - 1) return 1;
        int j = i - 1;
        while(j >= 0 && A[j] == A[i]) j--;
        i = j + 1;
    }
    return -1;
}
int Solution::solve(vector<int> &A) {
    if(A.size() == 0) return -1;
    bool zero = false, max_is_zero = true;
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == 0) zero = true;
        if(A[i] > 0) {
            max_is_zero = false;
            break;
        }
    }
    int large = 0;
    if(max_is_zero && zero) return 1;
    else if(max_is_zero && !zero) return -1;
    for(int i = 0 ; i < A.size() ; i++) {
        if(A[i] < 0) A[i] = 0;
        if(A[i] >= A.size()) {
            large++;
            A[i] = 0;
        }
    }
    for(int i = 0 ; i < A.size() ; i++){
        int index = A[i]%A.size();
        A[index]+=(A.size());
    }
    for(int i = A.size()-1 ; i >= 0 ; i--){
        A[i]/=A.size();
    }
    int temp = large;
    for(int i = A.size() - 1; i > 0; i--){
        if(i < A.size() - 1) temp+=A[i+1];
        if(A[i] == 0) continue;
        if(i == temp) return 1;
    }
    return -1;
}

//O(NlogN)
int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int sum = 0;
    for(int i = A.size()-1; i >=0; i--)
    {
        if(A[i] == sum) return 1;
        int j = i;
        while(j >=0 && A[j] == A[i]) {
            sum++;
            j--;
        }
        i = j + 1;
    }
    return -1;
}

//O(n) time and O(1) space
int Solution::solve(vector<int> &A) {
    int n = A.size() - 1;
    int large = 0,small = 0;
    for(int i = 0; i<A.size();i++)
    {
        if(A[i] == 0) small++;
    }
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] >= A.size()) {
            if(A[i] > 0) large++;
            A[i] = 0;
        }
    }
    for(int i = 0; i< A.size(); i++)
    {
        A[A[i]%(n+1)]+=(n+1);
    }
    for(int i = 0;i < A.size();i++)
    {
        A[i]/=(n+1);
    }
    A[0] = small;
    for(int i = n;i>=0;i--)
    {
        if(A[i] == 0) continue;
        if(i == large) return 1;
        if(A[i] > 0) large+=A[i];
    }
    return -1;
}


//

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    for(int i = A.size()-1;i>=0;i--)
    {
        if(A[i] == A.size()-1-i)
        {
            if(i == A.size()-1 || (i < A.size()-1 && A[i+1]!= A[i]))
                return 1;            
        }
    }
    return -1;
}


//after Reset
//Take care of corner cases, like duplicates and -ve numbers
int Solution::solve(vector<int> &A) {
    if(A.size() == 0) return -1;
    sort(A.begin(),A.end());
    if(A[A.size()-1] == 0) return 1;
    for(int i = A.size()-1;i>=0;i--)
    {
        if(i!=A.size()-1 && A[i+1]!=A[i] && A[i] == A.size()-1-i) return 1;
    }
    return -1;
}
