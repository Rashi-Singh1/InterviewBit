/*working solution*/
vector<int> Solution::maxset(vector<int> &A) {
    vector<int> result;
    long long int first=0,last=0,firstIndex=0,lastIndex=0,ans=0,sum=0;
    for(int i=0;i<=A.size()-1;i++)
    {
        if((sum+(long long int)A[i]>=0) && (long long int)A[i]>=0)
        {
            sum=sum+(long long int)A[i];
            last++;
        }
        else
        {
            sum=0;
            first=(long long int)i+1;
            last=(long long int)i+1;
        }
        if(sum>=ans)
        {
             if(sum>ans)
            {
                //cout<<"yes"<<" ";
                firstIndex=first;
                lastIndex=last;    
            }
            else
            {
                if((last-first)>(lastIndex-firstIndex))
                {
                    firstIndex=first;
                    lastIndex=last;
                }
            }
            ans=sum;
            
        }
        //cout<<" first:"<<first<<" last "<<last<<" firstIndex:"<<firstIndex<<" lastIndex:"<<lastIndex<<" ans:"<<ans<<" sum:"<<sum<<" ";
    }
    //cout<<firstIndex<<" "<<lastIndex<<" ";
    for(long long int i=firstIndex;i<lastIndex;i++)
    {
        result.push_back(A[i]);
    }
    return result;
}


/*My refined solution*/
vector<int> Solution::maxset(vector<int> &A) {
    vector<int> ans;
    long long int localSum = 0,start = 0,end = 0,s = 0,globalSum;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] < 0)                //here not checking if localsum -ve then make 0 (bcs dont need negative part anyway)
        {                           //here checking that no entry should be -ve, so a tighter constraint
            s = i+1;
            localSum = 0;
        }
        else if(A[i] >= 0)
        {
            localSum +=A[i];
            if(localSum > globalSum)
            {
                globalSum = localSum;
                end = i;
                start = s;
            }else if(localSum == globalSum)
            {
                if(i-s > end - start)
                {
                    globalSum = localSum;
                    end = i;
                    start = s;
                }
            }
        }
    }
    if(start == 0 && end == 0 && A[0] < 0)
    {
        //
    }
    else
        for(int i = start;i<=end;i++)
        {
            ans.push_back(A[i]);
        }
    return ans;
}


//after Reset
vector<int> Solution::maxset(vector<int> &A) {
    if(A.size() == 0) return A;
    else{
        int start = 0;
        int s = 0 ;
        int e = 0;
        long long int lMax = 0;
        long long int gMax = 0;
        for(int i = 0;i<A.size();i++)
        {
            if(A[i] < 0)
            {
                start = i+1;
                lMax = 1ll*0;
            }else{
                lMax += 1ll*A[i];
                if((lMax > gMax) || ( lMax == gMax && i-start > e-s))
                {
                    gMax = lMax;
                    s = start;
                    e = i;
                }
            }
        }
        vector<int> ans;
        if(s == 0 && e ==0 && A[0] < 0)
        {
            return ans;
        }
        for(int i = s;i<=e;i++)
        {
            ans.push_back(A[i]);
        }
        return ans;
    }
}
