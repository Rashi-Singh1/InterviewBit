//For placements - 

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