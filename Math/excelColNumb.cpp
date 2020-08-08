int Solution::titleToNumber(string A) {
    int ans = 0;
    for(int i = 0; i < A.size(); i++){
        ans = ans*26 + (A[i]-'A' + 1);
    }
    return ans;
}


/*My sol*/
int Solution::titleToNumber(string A) {
    long long int count = 0;
    for(int i = 0;i<A.size();i++)
    {
        count+= (((int)(A[i]-'A')+1)*pow(26,A.size()-1-i));
    }
    return count;
}

/*Better sol*/
class Solution {
public:
    int titleToNumber(string s) {
       int result = 0;
       for (int i = 0; i < s.size(); i++) {
               result = result * 26 + (s[i] - 'A' + 1);
       }
       return result;
    }
};


//After reset
int Solution::titleToNumber(string A) {
    int ans = 0;
    for(int i = 0;i<A.size();i++)
    {
        ans+=(pow(26,A.size()-1-i)*((int)(A[i]-'A')+1));
    }
    return ans;
}
