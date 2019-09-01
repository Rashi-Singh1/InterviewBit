#include <iostream>
using namespace std;
#include <vector>

int search(const vector<int> &A, int B) {
    int start = 0;
    int end = A.size()-1;
    int mid,pivot = -1;
    while(start <= end)
    {
        mid = (start+end)/2;
        //cout<<start<<" "<<mid<<" "<<end<<endl;
        if(A[mid] < A[end])
        {
            if(mid > 0 && A[mid-1] >= A[end])
            {
                //cout<<"1 "<<endl;
                pivot = mid;
                break;
            }
            else
            {
                //cout<<"2 "<<endl;
                end = mid-1;
            }
        }
        else if (start == end)
        {
            //cout<<"3 "<<endl;
            pivot = start;
            break;
        }
        else
        {
            if(mid < A.size()-1 && A[mid+1] <= A[end])
            {
                //cout<<"4 "<<endl;
                pivot =  mid+1;
                break;
            }
            else
            {
                //cout<<"5 "<<endl;
                start = mid+1;
            }
        }
    }
    if(pivot==-1) pivot = start;
    //cout<<pivot<<endl;
    if(B == A[pivot]) return pivot;
    else if(B < A[pivot])
    {
        return -1;
    }else{
        if(B > A[A.size()-1])
        {
            start = 0;
            end = pivot-1;
        }else if(B == A[A.size()-1]){
            return A.size()-1;
        }else{
            start = pivot;
            end = A.size()-1;
        }
    }
    //cout<<"start "<<start<<"  end "<<end<<endl;
    while(start <= end)
    {
        mid = (start+end)/2;
        //cout<<start<<" "<<mid<<" "<<end<<endl;
        if(A[mid] == B) return mid;
        else if(A[mid] < B) start = mid+1;
        else end = mid-1;
        
    }
    return -1;
}


int main()
{
    vector<int> A = {1,2,3,4,5,6,0};
    int B = 2;
    cout<<search(A,B)<<endl;
}


//after reset
int Solution::search(const vector<int> &A, int B) {
    if(A.size() == 0) return -1;
    int start = 0;
    int end = A.size()-1;
    int pivot;
    while(start <= end)
    {
        int mid = (start +  end)/2;
        pivot = mid;
        if(A[mid] > A[end]) 
        {
            if(mid < end && A[mid+1] <= A[end]) {
                pivot =  mid+1;
                break;
            }
            else start = mid+1;
        }
        else if(A[mid] <= A[end])
        {
            if(mid > start && A[mid-1] > A[end]) {
                pivot =  mid;
                break;
            }
            else end = mid-1;
        }
    }
    if(A[pivot] == B) return pivot;
    else{
        if(B < A[pivot]) return -1;
        else{
            if(B < A[A.size()-1])
            {
                start = pivot;
                end = A.size()-1;
            }
            else{
                start = 0;
                end = pivot-1;
            }
            while(start <= end)
            {
                int mid = (start + end)/2;
                if(A[mid] == B) return mid;
                else if(A[mid] < B) start = mid+1;
                else end = mid-1;
            }
            return -1;
        }
    }
}
