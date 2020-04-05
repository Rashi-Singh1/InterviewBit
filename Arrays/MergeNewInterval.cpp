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
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//O(n) solution without sorting
vector<Interval> Solution::insert(vector<Interval> &A, Interval ni) {
    vector<Interval> ans;
    if(A.size() == 0) {
        ans.push_back(ni);
        return ans;
    }
    if(ni.end < A[0].start) ans.push_back(ni);
    Interval temp = A[0];
    if(ni.end >= temp.start && ni.start <= temp.end){
        temp.start = min(temp.start,ni.start);
        temp.end = max(temp.end,ni.end);
    }
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i].start <= temp.end) temp.end = max(temp.end,A[i].end);
        if(ni.start >= temp.start && ni.start <= temp.end){
            temp.end = max(temp.end,ni.end);
        }
        if(A[i].start <= temp.end) temp.end = max(temp.end,A[i].end);
        else{
            ans.push_back(temp);
            if(ni.start > temp.end && ni.start < A[i].start) {
                temp = ni;
                if(A[i].start <= temp.end) temp.end = max(ni.end,A[i].end);
            }
            else temp = A[i];
        }
    }
    ans.push_back(temp);
    if(ni.start > temp.end) ans.push_back(ni);
    if(A[A.size()-1].start > temp.end) ans.push_back(A[A.size()-1]);
    return ans;
}

bool comp(Interval one, Interval two) {
    if(one.start < two.start) return true;
    else if(one.start == two.start && one.end < two.end) return true;
    else return false;
}

vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    A.push_back(newInterval);
    vector<Interval> ans;
    
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
