vector<int> fibs;

void calFib(int A)
{
    int a = 1;
    int b = 1;
    while(a+b <= A)
    {
        fibs.push_back(min(a,b));
        int temp = a+b;
        a = b;
        b = temp;
    }
    fibs.push_back(min(a,b));
    fibs.push_back(max(a,b));
}

int floorSearch(int A)
{
    int start = 0;
    int end = fibs.size()-1;
    while(start<=end)
    {
        if(fibs[start] > A) return -1;
        if(fibs[end] <= A) return end;
        int mid = (start+end)/2;
        if(fibs[mid] == A) return mid;
        else if(fibs[mid] < A)
        {
            if(mid < end && fibs[mid+1] > A) return mid;
            else start = mid+1;
        }
        else{
            if(mid > start && fibs[mid-1] <= A) return mid-1;
            else end = mid-1;
        }
    }
    return -1;
}

int Solution::fibsum(int A) {
    if(A < 2) return A;
    fibs.clear();
    calFib(A);
    int ans = 0;
    while(A > 0)
    {
        int index = floorSearch(A);
        if(index == -1) return 0;
        else {
            ans++;
            A-=fibs[index];
        }
    }
    return ans;
}
