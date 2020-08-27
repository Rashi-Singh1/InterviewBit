struct node{
	unordered_map<char, node*> s;
	bool end;
	node(){end = false;}
	node(char c) {s[c] = NULL; end = false;}
};

struct trie{
	node* root;
	trie(){this->root = NULL;}
	void insert(string A);
	int search(string A);
};

void trie::insert(string A){
	if(A.size() == 0) return;
	if(this->root == NULL) this->root = new node();
	node* cur = this->root;
	string temp;
	for(auto x : A){
	    if(cur->s.count(x) == 0) cur->s[x] = new node();
	    cur = cur->s[x];
	}
	cur->end = true;
}

int trie::search(string A){
	if(this->root == NULL) return 0;
	node* cur = this->root;
	for(auto x : A){
	    if(cur == NULL || cur->s.count(x) == 0) return 0;
	    cur = cur->s[x];
	}
	if(cur->end) return 1;
	else return 0;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    trie t; vector<int> ans; map<int, vector<int> > m; string temp;
    for(auto x : A){
        if(x == '_') {
            if(temp != "") {
                t.insert(temp); 
                temp = "";
            }
        }
        else temp.push_back(x);
    }
    if(temp != "") {t.insert(temp); temp = "";}
    for(int i = 0 ;i < B.size(); i++){
        int count = 0;
        for(auto x : B[i]){
            if(x == '_') {
                if(temp != "") {
                    count+=t.search(temp); 
                    temp = "";
                }
            }
            else temp.push_back(x);
        }
        if(temp != "") {count+=t.search(temp); temp = "";}
        m[count].push_back(i);
    }
    for(auto x = m.rbegin(); x != m.rend(); x++) for(auto y : x->second) ans.push_back(y);
    return ans;
}