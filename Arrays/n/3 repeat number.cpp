#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A) {
    int size = A.size();
    if(size == 0) return -1;
    if(size < 3) return A[0];
    int start1 = INT_MAX, start2 = INT_MAX, count1 = 0, count2 = 0;
    for(int i = 0 ; i < size ; i++){
        if(A[i] == start1) count1++;
        else if(A[i] == start2) count2++;
        else if(count1 == 0) {
            start1 = A[i];
            count1++;
        }
        else if(count2 == 0){
            if(A[i] == start1) count1++;
            else {
                start2 = A[i];
                count2++;
            }
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(auto x : A){
        if(x == start1) count1++;
        else if(x == start2) count2++;
    }
    if(count1 > (size / 3)) return start1;
    if(count2 > (size / 3)) return start2;
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {727, 727, 641, 517, 212, 532, 727, 100, 254, 106, 405, 100, 736, 727, 727, 787, 105, 713, 727, 333, 69, 727, 877, 222, 727, 505, 641, 533, 727, 727, 727, 508, 475, 727, 573, 727, 618, 727, 309, 486, 792, 727, 727, 426, 547, 727, 972, 575, 303, 727, 533, 669, 489, 727, 329, 727, 050, 209, 109};
    cout<<repeatedNumber(A);
    return 0;
}


/*
SOME IMPORTANT OBSERVATIONS : 

It is important to note that if at a given time, you have 3 distinct element from the array, if you remove them from the array, your answer does not change.

The idea is if we remove one majority element and one minority element the majority element remains the same. How the numbers are removed it by keeping track of a ‘selected number’ initialized by index 0. we compare it to the A[i] for 0<i<n. Every time we see A[selected] == A[i] we increase count of selected number else we decrease the count. Decreasing the count means you have removed A[i] and one copy of the A[selected]. If the count reaches 0, you update the selected = i and keep on doing the process. In the end a check is required to see if A[selected] is really the number which occurs > n/2 times. This can be easily done in one iteration of the array.
Now let’s say we want to see if a number occurs more than n/k times. If we remove k-1 minority elements and 1 majority element the majority element remains the same. K was 2 in our previous case. For this questions k = 3, hence we remove 3 distinct numbers, and at the end check if any of the 2 numbers we kept is occurring more than n/3 or not.
*/