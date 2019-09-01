vector<string> ans;

int binaryToDecimal(string num) 
{ 
    int dec_value = 0; 
    int base = 1; 
    for (int i = 0; i < num.length(); i++) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
    return dec_value; 
} 
vector<int> Solution::grayCode(int A) {
    ans.clear();
    if(A == 0) {
        vector<int> ans;
        return ans;
    }
    ans = {"0","1"};
    for(int i = 1;i<A;i++)
    {
        int blah = ans.size();
        for(int j = blah-1;j>=0;j--)
        {
            ans.push_back( ans[j] + "1");
            ans[j] = ans[j] + "0";
        }
    }
    long long int tot = ans.size();
    vector<int> final;
    while(tot)
    {
        string temp = ans[ans.size()-1];
        ans.pop_back();
        tot--;
        final.push_back(binaryToDecimal(temp));
    }
    reverse(final.begin(),final.end());
    return final;
}

//see better solution from submissions


