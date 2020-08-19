int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> s; s.push(0);
    A.insert(A.begin(),0); A.push_back(0);
    int ans = INT_MIN;
    for(int i= 1 ; i < A.size(); i++){
        while(A[i] < A[s.top()]) {
            int last = s.top();
            s.pop();
            int area = A[last] * (i-1 - s.top());     //e are being considered, A[last] would be the min height, (bcs last height smaller than this is in stack)
            ans = max(area, ans);
        }
        s.push(i);
    }
    return ans;
}