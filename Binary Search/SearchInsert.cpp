int Solution::searchInsert(vector<int> &array, int x) {
  int start = 0;
  int end = array.size()-1;
  while(start<=end)
    {
        if(array[end] < x) return array.size();
        if(array[start] >= x) return start;
        int mid = (start+end)/2;
        if(array[mid] == x) return mid;
        else if(array[mid] < x)
        {
            if(mid+1 <=end && array[mid+1] >= x)
                return mid+1;
            else
                start = mid+1;
        }
        else{
            if(mid-1 >=start && array[mid-1]<x)
                return mid;
            else
                end = mid-1;
        }
    }
    return array.size();
}


/*Take care that when u r passing vector, pass it by ref, otherwise TLE(poora vector bhejne main time lagta h) or don't pass it at all, i.e. do it in the solution function
*/

//after reset
int Solution::searchInsert(vector<int> &A, int B) {
    int start = 0;
    int end = A.size()-1;
    while(start <= end)
    {
        if(B < A[start]) return 0;
        if(B > A[end]) return end+1;
        int mid = (start + end)/2;
        if(A[mid] == B) return mid;
        else if(A[mid] < B)
        {
            if(mid < end && A[mid+1] > B) return mid+1; 
            else start = mid + 1;
        }else{
            if(mid > start && A[mid-1] < B) return mid;
            else end = mid-1;
        }
    }
    return 0;
}
