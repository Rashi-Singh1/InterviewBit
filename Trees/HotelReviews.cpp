struct node{
    unordered_map<char,node*> sta;
    bool end;
    node()
    {
        sta.clear();
        end = false;
    }
};

class Trie{
    private: 
        node* root;
    public:
        Trie()
        {
            this->root = NULL;
        }
        
        void insert(string A)
        {
            if(this->root == NULL) this->root = new node();
            node* temp = this->root;
            for(int i = 0;i<A.size();i++)
            {
                if(temp->sta.count(A[i]) == 0) temp->sta[A[i]] = new node();
                temp = temp->sta[A[i]];
            }
            temp->end = true;
        }
        
        bool search(string A)
        {
            if(this->root == NULL || A.size() == 0) return false;
            node* temp = this->root;
            for(int i = 0;i<A.size();i++)
            {
                if(temp == NULL) return false;
                if(temp->sta.count(A[i]) == 0) return false;
                temp = temp->sta[A[i]];
            }
            if(temp->end == true) return true;
            else return false;
        }
};

vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int> ans;
    vector<string> good;
    string temp;
    for(int i = 0;i<A.size();i++)
    {
        if(A[i] == '_')
        {
            if(temp!="") {
                good.push_back(temp);
                temp = "";
            }
        }
        else temp.push_back(A[i]);
    }
   if(temp!="") {
        good.push_back(temp);
        temp = "";
   }
    // for(auto x : good) cout<<x<<" "; cout<<endl;
    Trie my;
    for(int i = 0;i<good.size();i++)
    {
        my.insert(good[i]);
    }
    map<int, vector<int> > mymap;
    for(int i = 0;i<B.size();i++)
    {
        vector<string> temp;
        string temp2;
        for(int j = 0;j<B[i].size();j++)
        {
            if(B[i][j] == '_')
            {
                if(temp2!="") {
                    temp.push_back(temp2);
                    temp2 = "";
                }
            }
            else temp2.push_back(B[i][j]);
        }
        if(temp2!="") {
            temp.push_back(temp2);
            temp2 = "";
        }
        // for(auto x : temp) cout<<x<<" "; cout<<endl;
        int count = 0;
        for(int j = 0;j<temp.size();j++)
        {
            if(temp[j]!="" && my.search(temp[j])){
                count++;
            }
        }
        mymap[count].push_back(i);
        // cout<<i<<" "<<count<<endl;
    }
    while(mymap.size() > 0)
    {
        auto y = mymap.rbegin()->second;
        for(int i = 0;i<y.size();i++)
        {
            ans.push_back(y[i]);
        }
        mymap.erase(mymap.rbegin()->first);
    }
    return ans;
}


