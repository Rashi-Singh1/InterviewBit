struct node{
    unordered_map<char,node* > sta;
    bool end;
    node()
    {
        this->sta.clear();
        this->end = NULL;
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
        
        string ShortestPrefix(string A)
        {
            if(this->root == NULL || A.size() == 0) return "";
            node* temp = this->root;
            string ans;
            int pointer = 0;
            for(int i = 0;i<A.size();i++)
            {
                if(temp->sta.size() > 1) 
                {
                    for(int j = pointer; j<=i ; j++)
                    {
                        ans.push_back(A[j]);
                    }
                    pointer = i+1;
                }
                temp = temp->sta[A[i]];
            }
            if(ans == "") ans.push_back(A[0]);
            return ans;
        }
};

vector<string> Solution::prefix(vector<string> &A) {
    Trie my;
    for(int i = 0 ;i<A.size();i++)
    {
        my.insert(A[i]);
    }
    vector<string> ans;
    for(int i = 0;i<A.size();i++)
    {
        ans.push_back(my.ShortestPrefix(A[i]));
    }
    return ans;
}
