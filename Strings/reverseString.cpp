string sol(string &A)
{
	string delim = " ";
	string ans;
	string token;
	size_t pos;
	while((pos = A.find(delim)!=std::string::npos))
	{
		if(!(token == " " || token.size() == 0))
			ans = token + " " + ans;
		A.erase(0,pos+delim.length());
	}
	A = A + " " + ans;
	int k = 0;
	while(k<A.size())
	{
		if(A[k] == ' ')
		{
			k++;
		}
		else{
			break;
		}
	}
	A = A.substr(k);
	k = A.size();
	while(k>0)
	{
		if(A[k-1] == ' ')
		{
			k--;
		}else{
			break;
		}
	}
	A = A.substr(0,k);
}

//after reset
void Solution::reverseWords(string &A) {
    if(A.size() > 0){
        int i = 0;
        while(i < A.size())
        {
            if(A[i] == ' ') i++;
            else break;
        }
        string temp;
        string ans;
        for(int j = i;j<A.size();j++)
        {
            if(A[j]!=' ') temp+=A[j];
            else {
                if(!(temp == " " || temp == "")) ans = temp + " " + ans;
                temp = "";
            }
        }
        ans = temp + " " + ans;
        A = ans;
        i = A.size();
        while(i>0)
        {
            if(A[i-1] == ' ') i--;
            else break;
        }
        A = A.substr(0,i);
        i = 0;
        while(i < A.size())
        {
            if(A[i] == ' ') i++;
            else break;
        }
        A = A.substr(i);
    }
}