#include <iostream>
#include <vector>
using namespace std;

void getPrefixSuffix(string sub, vector<int>& LSA){
    int i = 0;
    for(int j = 1; j < sub.size(); j++){
        if(sub[i] == sub[j]){
            LSA[j] = i + 1;
            i++;
        }
        else{
            if(i == 0) LSA[j] = 0;
            else{
                i = LSA[i-1];
                j--;
            }
        }
    }
}

bool subset(string sup, string sub){
    if(sub.size() > sup.size()) return false;
    if(sub.size() == 0) return true;

    vector<int> LSA(sub.size(),0);
    getPrefixSuffix(sub, LSA);
    
    int supIdx = 0, subIdx = 0;
    for(supIdx = 0; supIdx < sup.size(); supIdx++){
        if(subIdx == sub.size()) return true;
        if(sup[supIdx] == sub[subIdx]) subIdx++;
        else{
            if(subIdx != 0){
                subIdx = LSA[subIdx - 1];
                supIdx--;
            } 
        }
    }
    if(subIdx == sub.size()) return true;
    return false;
    
}

int main(){
    // cout<<subset("abcdabcabceabc","abcacd")<<endl;
    cout<<subset("abcacfkjhbabcacdfjh","abcacd")<<endl;
    return 0;
}