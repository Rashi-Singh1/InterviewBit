#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int num;
struct tree{
    vector<int> A;
    tree(){}
    void insert(int index, int start, int end);
    void update(int index, int start, int end, int curIndex);
    int query(int start, int end, int curIndex);
    void print();
};

void tree::insert(int index, int start, int end){
    if(start > end) return;
    while(A.size() <= index) A.push_back(0);
    if(end > start) this->insert(2*index+1, start, (start+end)/2);
    this->insert(2*index+2, (start+end)/2 + 1, end);
    if(start == end) A[index] = 1;
    else A[index] = A[2*index+1] + A[2*index+2];
}

void tree::update(int index, int start, int end, int curIndex){
    if(start > end) return;
    if(start == end && end == index) this->A[curIndex] = 0;
    else if(start <= index && index <= end){
        if(end > start) update(index, start, (start+end)/2, 2*curIndex+1);
        update(index, (start+end)/2+1, end, 2*curIndex+2);
        this->A[curIndex] = A[2*curIndex+1] + A[2*curIndex+2];
    }
    else return;
}

int tree::query(int start, int end, int curIndex){
    if(start > end || num < 0) return -1;
    if(A[curIndex] == 0) return -1;
    if(start == end) {
        if(num == 0) return start;
        num--;
    }
    if(start != end){
        int temp;
        if(end > start) temp = query(start, (start+end)/2, 2*curIndex+1);
        if(temp == -1) temp = query((start+end)/2 + 1, end, 2*curIndex+2);
        if(temp != -1){
            if(num == 0) return temp;
            num--;
        }
    }
    return -1;
}

void tree::print(){
    for(auto x : A) cout<<x<<" "; cout<<endl;
}

vector<int> order(vector<int> &A, vector<int> &B) {
    tree t; t.insert(0, 0, A.size()-1);
    // t.print();
    vector<pair<int,int> > pairs; vector<int> ans(A.size());
    for(int i = 0 ; i < A.size(); i++) pairs.push_back({A[i], B[i]});
    sort(pairs.begin(), pairs.end(), [](pair<int, int>& a, pair<int,int>& b){
        return a.first <= b.first;
    });
    for(auto x : pairs){
        num = x.second;
        int index = t.query(0, A.size()-1, 0);
        if(index >= 0 && index < ans.size()) {
            ans[index] = x.first;
            t.update(index, 0, A.size()-1, 0);
            // t.print();
            // for(auto y : ans) cout<<y<<" "; cout<<endl;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]){
    vector<int> A = { 5, 3, 2, 6, 1, 4 }, B = { 0, 1, 2, 0, 3, 2 };
    vector<int> ans = order(A, B);
    for(auto x : ans) cout<<x<<" "; cout<<endl;
    return 0;
}
