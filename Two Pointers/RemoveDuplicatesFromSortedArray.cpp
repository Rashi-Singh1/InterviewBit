int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() < 2) return A.size();
    int cur = 0;
    int next = 1;
    bool repeat = false;
    for(;next < A.size(); next++){
        if(A[cur] == A[next]){
            if(repeat == false) {
                repeat = true;
            }
        }
        else{
            cur++;
            A[cur] = A[next];
            repeat = false;
        }
    }
    A.resize(distance(A.begin(), A.begin() + cur+1));
    return cur+1;
}


int Solution::removeDuplicates(vector<int> &A) {
    int cur = -1;
    bool used = false;
    int count = 0;
    int trash = A[0];
    for(int i = 1;i<A.size();i++)
    {
        // cout<<" echo "<<endl;
        if(A[i] == trash)
        {
            count++;
        }
        if(A[i] == trash && used == false)
        {
            cur = i;
            used = true;
        }
        else if(A[i]!=trash){
            
            if(cur == -1)
            {
               //do not use continue here bcs then it would not set trash
            }else{
                A[cur] = A[i];
                used = false;
                //making it false here updates current jab aur koi repeat hoga, we want it to be after the newly set value
                cur++;
            }
        }
        trash = A[i];
    }
    //use erase from behind to get best case scenario
    int ans = A.size()-count;
    for(int i = 0;i<count;i++)
    {
        if(A.size()-1 >=0) A.erase(A.begin()+A.size()-1);
    }
    return ans;
}

//after reset : bahut acha h ye
int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() == 0) return 0;
    int trash = A[0];
    int cur = 0;
    for(int i = 1;i<A.size();i++)
    {
        if(A[i] == trash) {
            cur = i;
            break;
        }
        trash = A[i];
    }
    int temp = cur;
    if(cur > 0)
    {
        trash = A[cur];
        for(int i = temp+1;i<A.size();i++)
        {
            if(A[i]!=trash)
            {
                A[cur] = A[i];
                cur++;
            }
            trash = A[i];
        }
    }
    else{
        return A.size();
    }
    return cur;
}
