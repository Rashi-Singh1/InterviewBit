vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> ans;
    if(A.size() == 0 || B.size() == 0) return ans;
    // std::sort(B.begin(), B.end());
    
    // sort(B.begin(),B.end());
    unordered_map<int,int> sta; //index in B, starting index in A
    int start = 0;
    int end = 0;
    while(end < A.size())
    {
        // cout<<start<<" "<<end<<endl;
        if(end < A.size()-B[0].size() + 1) {
            // cout<<"eco"<<endl;
            string temp = A.substr(end,B[0].size());
            bool flag = false;
            bool done = false;
            for(int i = 0;i<B.size();i++)
            {
                // cout<<"i "<<i<<endl;
                if(temp == B[i]) 
                {
                    if(sta.count(i) !=0 ) {
                        // cout<<"echo3 "<<i<<endl;
                        if(sta[i] < start) {
                            sta[i] = end;
                            flag = true;
                            // if(start >=28) cout<<"echo "<<end<<endl;
                            break;
                        }
                        else{
                            // cout<<"bla "<<endl;
                            // i++;  
                        }
                            //for duplicates
                    }
                    else {
                        sta.insert(make_pair(i,end));
                        // cout<<"echo2 "<<end<<endl;
                        flag = true;
                        break;
                    }
                    done = true;
                }
            }
            // cout<<"echo "<<end-start<<" "<<((B.size()-1)*(B[0].size()))<<" falg "<<flag<<endl;
            if(flag == true && end-start <= ((B.size()-1)*(B[0].size()))) {
                bool tri = true;
                for(int i = 0;i<B.size();i++)
                {
                    // cout<<"i "<<i<<endl;
                    if(sta.count(i) > 0 && sta[i] >= start) continue;
                    else {
                        tri = false;
                        break;
                    }
                }
                if(tri == true) {
                    // cout<<"echo     kjlk "<<endl;
                    ans.push_back(start);
                    start += B[0].size();
                }
                end+=B[0].size();
            }
            else {
                if(flag == true || done == true)
                {
                    start+=B[0].size();
                    // end+=B[0].size();
                }
                else{
                    end++;
                    start = end;
                }
            }
        }
        else return ans;
    }
    return ans;
}
