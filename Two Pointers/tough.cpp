#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int sol2(vector<int> &A, int B)
{
    int n=A.size();
    int start=0;
    int end=0;
    int ans_start=0;
    int ans_end=0;
    int prev=-1;
    int maxLen=INT8_MIN;
    int count=0;
    vector<int> zeroes;
    int zero=0;
    while(end<n){
        if(A[end]==1){
            if((end-start+1)>maxLen){
                maxLen=(end-start+1);
                ans_start=start;
                ans_end=end;
            }
            end++;
        }
        else if(A[end]==0){
            zeroes.push_back(end);
            count++;
            if(count>B){
                start=zeroes[zero++]+1;
            }
            if((end-start+1)>maxLen){
                maxLen=(end-start+1);
                ans_start=start;
                ans_end=end;
            }
            end++;
        }
    cout<<start<<" "<<end<<" "<<count<<" "<<ans_start<<" "<<ans_end<<endl;
    }
    vector<int>ans;
    cout<<start<<" "<<end<<" "<<ans_start<<" "<<ans_end<<endl;
    for(int i=ans_start;i<=ans_end;i++){
        ans.push_back(i);
    }
    cout<<"Second ans : "<<endl;
    for(int i = 0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
}

int sol1(vector<int> &A, int B)
{
    int start = 0;
    int end = 0;
    int localCount = 0;
    int ansStart = 0;
    int ansEnd = 0;
    queue<int> zero;
    while(start < A.size()  && end < A.size())
    {
        if(A[end] == 0)
        {
            localCount++;
            zero.push(end);
            if(localCount > B)
            {
                int firstOne = zero.front();
                zero.pop();
                if((end-start) > (ansEnd - ansStart) ){
                    ansEnd = end;
                    ansStart = start;
                }
                start = firstOne+1;
                end = firstOne+1;
                if(firstOne+1 < A.size()) localCount = abs(A[firstOne+1]-1);
            }
        }
        cout<<start<<" "<<end<<" "<<localCount<<" "<<ansStart<<" "<<ansEnd<<endl;
        // if(localCount > B){
        //     start++;
        // }
        end++;
    }
    cout<<start<<" "<<end<<" "<<ansStart<<" "<<ansEnd<<endl;
    if((end-start) > (ansEnd - ansStart) ){
        ansEnd = end;
        ansStart = start;
    }
    cout<<ansStart<<" "<<ansEnd<<endl;
    vector<int> ans;
    for(int i = ansStart;i<ansEnd;i++)
    {
        ans.push_back(i);
    }cout<<"My ans : "<<endl;
    for(int i = 0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
}

int main()
{
    vector<int> A = {0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0};
    int B = 0;
    sol1(A,B);
    sol2(A,B);
}