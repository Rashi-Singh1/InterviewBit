//after reset
int binarySearch(vector<int> &A, int start, int end, int x)
{
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(A[mid] == x) return mid;
        else if(A[mid] < x) start =  mid+1;
        else end = mid-1;
    }
    return -1;
}

int floorSearch(vector<int> &A, int start, int end, int x)
{
    while(start <= end)
    {
        if(x < A[start]) return -1;
        if(x >= A[end]) return end;
        int mid = (start+end)/2;
        // cout<<"1   "<<start<<" "<<mid<<" "<<end<<endl;
        if(A[mid] == x) return mid;
        else if( A[mid] < x)
        {
            if(mid < end && A[mid+1] >x)
                return mid;
            else
                start = mid + 1;
        }
        else
        {
            if(mid > start && A[mid-1] <= x)
                return mid-1;
            else
                end = mid-1;
        }
    }
    return -1;
}

int ceilSearch(vector<int> &A, int start, int end, int x)
{
    while(start <=end)
    {
        if(x >  A[end]) return -1;
        if(x <= A[start]) return start;
        int mid = (start + end)/2;
        if(A[mid] == x) return mid;
        else if(A[mid] < x)
        {
            if(mid < end && A[mid+1] >= x)
                return mid+1;
            else
                start = mid+1;
        }else{
            if(mid > start && A[mid-1] < x)
                return mid;
            else
                end = mid-1;
        }
    }
    return -1;
}

int Solution::solve(vector<int> &A, int len, int val) {
    if(A.size() == 0) return 0;
    if(len > ((int)log10(val)+1)) return 0;
    else if( len < ((int)log10(val)+1))
    {
        if(len == 1) return A.size();
        else{
            int index = binarySearch(A,0,A.size()-1,0);
            if(index == -1)
            {
                return pow(A.size(),len);
            }
            else{
                return (A.size()-1)*pow(A.size(),len-1);
            }
        }
    }else{
        int size = A.size();
        int ans = 0;
        int index = binarySearch(A,0,size-1,0);
        string numb = to_string(val);
        if(index == -1)         //if no zero
        {
            for(int i = 0;i<len;i++)
            {
                int temp = (int)(numb[i]-'0');
                int tempIndex = floorSearch(A,0,size-1,temp);
                int ceilIndex = ceilSearch(A,0,size-1,temp);
                int trash = tempIndex;          //need trash bcs tempIndex ko change karna tha and baad main check bhi karna tha at line 97
                if(tempIndex!=-1 && temp == A[trash])
                    trash--;                    //if floor returns the same value as the current number,i.t. temp
                ans+=(trash+1)*pow(size,len-i-1);
                if(tempIndex == -1 || ceilIndex == -1) return ans;      //ex A = {6} and val = 4444, then we can not have any value, as floor hi nhi mila, altho this cond is obsolete as ye next condition se bhi ho jata
                else if(A[ceilIndex] > temp) return ans;    //ex A = {2} len = 4 and val = 4444, then only one value,2222 (but counted twice), therefore if ceil is not present or greater, we wont have that place filled with temp when we check for next numbers
            }
        }
        else{           //if zero present
            for(int i = 0;i<len;i++)
            {
                int temp = (int)(numb[i]-'0');
                int tempIndex = floorSearch(A,0,size-1,temp);
                int ceilIndex = ceilSearch(A,0,size-1,temp);
                int trash = tempIndex;
                if(tempIndex != -1 && A[trash] == temp)
                    trash--;
                if(len == 1 || i!=0) ans+=((trash+1)*pow(size,len-1-i));
                else{
                    if(tempIndex>0) ans+=(trash*pow(size,len-1-i));
                    else if(tempIndex == -1 || ceilIndex == -1) return ans;
                }
                if(ceilIndex == -1 || (ceilIndex!=-1 && A[ceilIndex] > temp)) return ans;
            }
        }
        return ans;
    }
}