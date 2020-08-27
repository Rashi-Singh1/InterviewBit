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
	bool search(string A);
	string getSubstring(string A);
};

void trie::insert(string A){
	if(A.size() == 0) return;
	if(this->root == NULL) this->root = new node();
	node* cur = this->root;
	for(auto x : A){
		if(cur->s.count(x) == 0) cur->s[x] = new node();
		cur = cur->s[x];
	}
	cur->end = true;
}

bool trie::search(string A){
	if(this->root == NULL) return false;
	node* cur = this->root;
	for(auto x : A){
		if(cur == NULL || cur->s.count(x) == 0) return false;
		cur = cur->s[x];
	}
	return cur->end;
}

string trie::getSubstring(string A){
    if(A.size() < 2 || this->root == NULL) return A;
    string ans; node* temp = this->root; int tillThis = 0;
    for(int i = 0; i < A.size(); i++){
        if(temp == NULL) return ans;
        ans.push_back(A[i]);
        temp = temp->s[A[i]];
        if(temp && temp->s.size() > 1) tillThis = i+1;
    } 
    return A.substr(0,min(tillThis+1, (int)A.size()));
}

vector<string> Solution::prefix(vector<string> &A) {
    trie t; vector<string> ans;
    for(auto x : A) t.insert(x);
    for(auto x : A){
        ans.push_back(t.getSubstring(x));
    }
    return ans;
}