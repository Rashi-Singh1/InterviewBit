int floorSearch(vector<int> &A, int start, int end, int x)
{
    while(start <= end)
    {
        if(A[start] > x) return -1;
        else if(A[end] < x ) return end;
        int mid = (start + end)/2;
        if(A[mid] == x) return mid;
        else if(A[mid] < x)
        {
            if(mid+1 < A.size() && A[mid+1] > x)
                return mid;
            else
                start = mid+1;
        }else{
            if(mid - 1 >=0 && A[mid-1] <= x)
                return mid-1;
            else
                end = mid-1;
        }
    }
    return -1;
}

//bakwas
void Solution::merge(vector<int> &A, vector<int> &B) {
    int i = 0,j=0;
    int size = A.size();
    int index;
    while(j < B.size())
    {
        index = floorSearch(A,i,A.size()-1,B[j]);
        A.insert(A.begin()+index+1,B[j]);
        j++;
    }
}

//O((n+m)*Log(m+n)) time and O(1) space
void Solution::merge(vector<int> &A, vector<int> &B) {

    A.insert(A.begin(),B.begin(),B.end());
    sort(A.begin(),A.end());
}

//after reset O(m+n) space and time
void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i<A.size() && j < B.size())
    {
        if(A[i] <= B[j]) ans.push_back(A[i++]);
        else ans.push_back(B[j++]);
    }
    while(i < A.size()) ans.push_back(A[i++]);
    while(j < B.size()) ans.push_back(B[j++]);
    A.clear();
    for(int i = 0;i<ans.size();i++)
    {
        A.push_back(ans[i]);
    }
}
