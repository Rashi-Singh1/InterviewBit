//figured out this solution is actually wrong altho O(nLogn)
int Solution::solve(string A) {
    if(A.size()<2) return 0;
    int start = 0;
    int end = A.size()-1;
    int mid;
    int ans = 0;
    while(start<=end)
    {
        mid = (start+end)/2;
        //cout<<start<<" "<<mid<<" "<<end<<endl;
        string temp = A.substr(0,A.size()-mid);
        string reversed = temp;
        reverse(reversed.begin(),reversed.end());
        if(temp == reversed)
        {
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}

//after reset
//this is correct but is O(n^2)
void binarySearch(int start, int end, string A, int* ans)
{
    int mid;
    if(start<=end)
    {
        mid = (start+end)/2;
        string temp = A.substr(0,A.size()-mid);
        string reversed = temp;
        reverse(reversed.begin(),reversed.end());
        if(temp == reversed)
        {
            *ans = min(*ans,mid);
            binarySearch(start,mid-1,A,ans);
        }else{
            binarySearch(start,mid-1,A,ans);
            binarySearch(mid+1,end,A,ans);
        }
    }
}
int Solution::solve(string A) {
    if(A.size()<2) return 0;
    int start = 0;
    int end = A.size()-1;
    int mid;
    int ans = end;
    binarySearch(start,end,A,&ans);
    
    return ans;
}
