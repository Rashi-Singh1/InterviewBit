#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// generate all subarrays of A.
// take the maximum element from each subarray of A and insert it into a new array G.
// replace every element of G with the product of their divisors mod 1e9 + 7.
// sort G in descending order
// perform Q queries
// #define ll long long int

const int mn = 1e5 + 5;
const ll mod = 1e9 + 7;
ll power(ll a, ll g) {ll ag = 1; while(g){if(g&1) ag = (ag%mod * a%mod)%mod; a = (a%mod * a%mod)%mod; g >>= 1;} return ag;}

ll p[mn];

void pre_compute_product_of_divisors() {
    p[0] = 0; p[1] = 1;
    if(p[2] != 0) return;
    for(ll i = 2; i < mn; i += 1) {
        if(p[i] == 0) {
            p[i] = 2;
            for(ll j = i+i; j < mn; j += i) {
                if(p[j] == 0) p[j] = 1;
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) {
                    cnt += 1;
                    tmp /= i;
                }
                p[j] *= (cnt + 1);
            }
        }
    }
    for(int i = 2; i < mn; i += 1) {
        p[i] = (power(i, p[i]/2)%mod * (p[i]&1 ? (ll)sqrt(i) : 1)%mod)%mod;
    }
}

// comparator to sort in descending order
bool compare(pair<int, long long int> a, pair<int, long long int> g) {
    if(a.first == g.first)
        return a.second < g.second;
    else
        return a.first > g.first;
}

vector<int> solve(vector<int> &A, vector<int> &B) {
    
    pre_compute_product_of_divisors();
    
    int size = (int)A.size();
    // create arrays to store length of longest segment in which ith element is greater
    long long int left[size], right[size], lr[size];
    // initialize elements array equal to 1.
    for(int i = 0; i < size; i += 1) {
        left[i] = right[i] = 1;
    }
    // find next greater element to the left of the current element
    for(int i = 1; i < size; i += 1) {
        int last = i-1;
        while(last >= 0 and A[i] > A[last]) {
            left[i] += left[last];
            last -= left[last];
        }
    }
    // find next greater element to the right of the current element
    for(int i = size-2; i >= 0; i -= 1) {
        int last = i+1;
        while(last < size and A[i] >= A[last]) {
            right[i] += right[last];
            last += right[last];
        }
    }
    // The number of subarrays in which current element will be the greater
    for(int i = 0; i < size; i += 1) {
        lr[i] = left[i] * right[i];
    }
    // Sort elements in descending order according to there value
    pair<int, long long int> ag[size];
    for(int i = 0; i < size; i += 1) {
        ag[i] = {p[A[i]], lr[i]};
    }
    sort(ag, ag + size, compare);

    // Take Prefix Sum of frequencies of elements
    long long pre[size];
    pre[0] = ag[0].second;
    for(int i = 1; i < size; i += 1) {
        pre[i] = pre[i-1] + ag[i].second;
    }
    
    // do Binary search for each query
    int q = (int)B.size();
    vector<int> ans(q);
    for(int i = 0; i < q; i += 1) {
        auto id = lower_bound(pre, pre + size, B[i]) - pre;
        ans[i] = ag[id].first;
    }
    // return the ans array
    return ans;
}
// vector<int> solve(vector<int> &A, vector<int> &B) {
//     int size = A.size(), q = B.size();
//     if(size == 0) return A;
//     vector<int> ans;
//     if(q == 0) return ans;
//     vector<int> left, right;
//     for(int i = 0 ; i < size; i++){

//     }
// }

int main(int argc, char const *argv[])
{
    vector<int> A = {3,4,2,5,7,0};
    vector<int> B = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    // , 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    vector<int> ans = solve(A,B);
    for(auto x : ans) cout<<x<<" "; cout<<endl;
    return 0;
}
