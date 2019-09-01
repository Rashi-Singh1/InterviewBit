//after reset
string Solution::countAndSay(int A) {
    if(A == 1) return "1";
    string temp = countAndSay(A-1);
    string ans;
    for(int i = 0;i<temp.size();i++)
    {
        int trash = temp[i]-'0';
        int k = i;
        int count = 0;
        while((int)(temp[k]-'0') == trash)
        {
            count++;
            k++;
        }
        i = k-1;
        ans = ans+ to_string(count) + to_string(trash);
    }
    return ans;
}

string Solution::countAndSay(int A) {
    if(A == 1)
        return "1";
    else if(A == 2)
        return "11";
    else if(A == 3)
    {
        return "21";
    }
    else {
        string temp = countAndSay(A-1);
        string ans;
        int i = 0;
        while(i<temp.size())
        {
            int count = 0;
            if(temp[i] == '1')
            {
                while(i<temp.size())
                {
                    if(temp[i] == '1')
                    {
                        i++;
                        count++;
                    }else{
                        i--;
                        break;
                    }
                }
                ans+=to_string(count) + "1";
            }else if(temp[i] == '2')
            {
                while(i<temp.size())
                {
                    if(temp[i] == '2')
                    {
                        i++;
                        count++;
                    }else{
                        i--;
                        break;
                    }
                }
                ans+=to_string(count) + "2";
            }else{
                while(i<temp.size())
                {
                    if(temp[i] == '3')
                    {
                        i++;
                        count++;
                    }else{
                        i--;
                        break;
                    }
                }
                ans+=to_string(count) + "3";
            }
            i++;
        }
        return ans;
    }
}
