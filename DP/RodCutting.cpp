int floorSearch(vector<int>& B, int val, int start, int end)
{
    while(start <= end)
    {
        if(val < B[start]) return -1;
        if(val >= B[end]) return end;
        int mid = (start + end)/2;
        if(B[mid] == val) return mid;
        else if(B[mid] < val)
        {
            if( (mid+1) < end && B[mid + 1] > val) return mid;
            else start = mid+1;
        }
        else{
            if( (mid-1) > start && B[mid-1] <= val) return mid-1;
            else end = mid-1;
        }
    }
    return -1;
}

int ceilSearch(vector<int>& B, int val, int start, int end)
{
    while(start <= end)
    {
        if(val > B[end]) return -1;
        if(val <= B[start]) return start;
        int mid = (start + end)/2;
        if(B[mid] == val) return mid;
        else if(B[mid] < val)
        {
            if( (mid+1) < end && B[mid + 1] >= val) return mid+1;
            else start = mid+1;
        }
        else{
            if( (mid-1) > start && B[mid-1] < val) return mid;
            else end = mid-1;
        }
    }
    return -1;
}

vector<int> ans;

void solve(int A,int start, int end, vector<int>& B)
{
    if(start < end)
    {
        int mid = (start + end)/2 + 1;
        long long int flo = 1ll*floorSearch(B,mid,start, end);
        long long int cei = 1ll*ceilSearch(B,mid, start, end);
        long long int temp = -1;
        if(flo!=-1)
        {
            temp = flo;
        }
        if(cei!=-1)
        {
            if(flo == -1) temp = cei;
            else
                if(llabs(cei-mid) < llabs(flo-mid)) temp = cei;
        }
        if(temp == -1) return;
        ans.push_back(B[(int)temp]);
        solve(A,start,B[temp]-1,B);
        solve(A,B[(int)temp]+1,end,B);
    }
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    ans.clear();
    solve(A,0,B.size()-1,B);    
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
