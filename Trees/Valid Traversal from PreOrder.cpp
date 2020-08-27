int Solution::solve(vector<int> &A) {
    if(A.size() < 3) return 1;
    stack<int> s;
    s.push(A[0]);
    int center = INT_MIN;
    for(int i = 1; i < A.size(); i++){
        if(A[i] < center) return 0;
        while(!s.empty() && A[i] > s.top()) {center = s.top(); s.pop();} 
        s.push(A[i]);
    }
    return 1;
}

//LOGIC: 
/*
if values come in decreasing way, it means, they can be added on the left of one another
if at some point, a greater value than stack top arrives, we fix a center and add current value to right, after this, all values must be greater than center

try making a tree for {7 7 10 10 9 5 2 8} and you'll get the logic
*/