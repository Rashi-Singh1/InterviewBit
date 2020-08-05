#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

string getString(vector<int> &A, int start){
    string firstRow = "";
    int size = A.size();
    if(size == 0) return firstRow;
    for(int i = 0 ; i < size - 1; i++){
        firstRow+=to_string(A[(i+start)%size]);
        firstRow+=" ";
    }
    firstRow+=to_string(A[(size-1+start)%size]);
    return firstRow;
}

//using set
bool rowRotate(vector<vector<int> >& A){
    int row = A.size();
    if(row < 2) return true;

    int col = A[0].size();
    if(col == 0) return true;

    //O(N*M) worst case
    unordered_set<string> set;
    for(int i = 0 ; i < col; i++){
        set.insert(getString(A[0],i));
    } 

    //O(N) - best case and O(N*M) worst case
    for(int i = 1; i < row; i++){
        if(set.count(getString(A[i],0)) == 0) return false;
    }
    return true;
}

bool rowRotateArray(int** array){

}

int main(int argc, char const *argv[])
{
    // vector<vector<int> > A = {{1,12,1,11},{112,1,1,1},{11,1,1,12}};
    vector<vector<int> > A = {{1,12,1,11},{1,11,1,12},{11,1,12,1}};
    cout<<rowRotate(A)<<endl;
    return 0;
}
