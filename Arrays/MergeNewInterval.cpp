/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
    
bool compareInterval(Interval A, Interval B)
{
    return A.start<B.start;
}
vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    A.push_back(newInterval);
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
