/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//For placement - 

bool comp(Interval one, Interval two) {
    if(one.start < two.start) return true;
    else if(one.start == two.start && one.end < two.end) return true;
    else return false;
}
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    
    vector<Interval> ans;
    if(A.size() == 0) return ans;
    
    sort(A.begin(),A.end(),comp);
    
    Interval interval;
    interval.start = A[0].start;
    interval.end = A[0].end;
    
    for(int i = 1;i<A.size();i++)
    {
        if(A[i].start <= interval.end) interval.end = max(interval.end,A[i].end);
        else{
            ans.push_back(interval);
            interval.start = A[i].start;
            interval.end = A[i].end;
        }
    }
    ans.push_back(interval);
    return ans;
}

//



bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> ans;
    sort(A.begin(), A.end(),compareInterval); 
    Interval temp;
    temp.start = A[0].start;
    temp.end = A[0].end;
    for(int i = 1;i<A.size();i++)
    {
        if(A[i].start <= temp.end) temp.end = max(temp.end,A[i].end);
        else{
            ans.push_back(temp);
            temp.start =A[i].start;
            temp.end = A[i].end;
        }
    }
    ans.push_back(temp);
    return ans;

}


//after Reset
bool compareInterval(Interval A, Interval B)
{
    return A.start<B.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    if(A.size() == 0) return A;
    sort(A.begin(),A.end(),compareInterval);
    vector<Interval> ans;
    int start = A[0].start;
    int end = A[0].end;
    for(int i = 1;i<A.size();i++)
    {
        if(end >= A[i].start) end = max(end, A[i].end);
        else{
            Interval temp;
            temp.start = start;
            temp.end = end;
            ans.push_back(temp);
            start = A[i].start;
            end = A[i].end;
        }
    }
    Interval temp;
    temp.start = start;
    temp.end = end;
    ans.push_back(temp);
    return ans;
}
