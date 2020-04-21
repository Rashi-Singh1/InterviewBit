//For placements - 

//Floyd's tortoise and hare algo (bcs the sol was guaranteed in this case)
int Solution::repeatedNumber(const vector<int> &A) {
    if(A.size() < 2) return -1;
    int hare = A[0], tor = A[0];
    while(true){
        hare = A[A[hare]];
        tor = A[tor];
        if(hare == tor) break;
    }
    tor = A[0];
    while(tor != hare){
        tor = A[tor];
        hare = A[hare];
    }
    return hare;
}

//bucketing method
int Solution::repeatedNumber(const vector<int> &A) {
    if(A.size() < 2) return -1;
    if(A.size() == 2) return 1;
    int size = A.size();
    double root = sqrt(size);
    int iroot = sqrt(size);
    vector<int> buffer(iroot + 1,0);
    int bucket = -1;
    for(int i = 0; i < A.size(); i++){
        int index = (int)((A[i]-1)/(iroot+1));
        buffer[index]++;
    }
    for(int i = 0 ; i < buffer.size(); i++){
        if(buffer[i] != (iroot+1)){
            bucket = i;
            break;
        }
    }
    if(bucket == -1) return -1;
    unordered_map<int,int> count;
    for(int i = 0 ; i < A.size(); i++){
        if(((A[i] - 1)/(iroot + 1)) == bucket) count[A[i]]++;
    }
    for(auto x : count)
        if(x.second > 1) return x.first;
    return -1;
    
}

//Sol made using hints
//this one did not work
int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    double root = sqrt(n);
    vector<int> range((int)root+5,0);
    for(int i = 0;i < A.size();i++)
    {
        double where = (double)((double)A[i]/root);
        range[(int)where]++;
    }
    int max = -1;

    for(int i = 0;i<range.size();i++)
    {
        if((double)range[i] > root)  {
        
            max = i;
            map<int,int> count;
            for(int j = 0; j < A.size(); j++)
            {
                if((double)A[j] < root*((double)(max + (double)1)) && (double)A[j] >= root*((double)max))
                {
                    count[A[j]]++;
                }
            }
            for(auto x : count) {
                if(x.second > 1) return x.first;
            }
        } 
    }
    if(max == -1) return -1;
    return 0;
}

//