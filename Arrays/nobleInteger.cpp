//for placement - 

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
