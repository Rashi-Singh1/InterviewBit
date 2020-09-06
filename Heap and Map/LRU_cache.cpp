typedef long long ll;
typedef pair<ll, int> p;
int curCap, cap;
ll tim;
map<ll, int> q;
map<int, p> s;

LRUCache::LRUCache(int capacity) {
    curCap = 0; cap = capacity;
    tim = 0ll;
    s.clear();
    q.clear();
}

int LRUCache::get(int key) {
    if(s.count(key) > 0) {
        q.erase(s[key].first);
        q[tim] = key;
        s[key].first = tim++;
    }
    return (s.count(key) == 0 ? -1 : s[key].second); 
}

void LRUCache::set(int key, int value) {
    if(s.size() == 0) tim = 0ll;
    if(curCap >= cap && s.count(key) == 0){
        s.erase(q.begin()->second);
        q.erase(q.begin()->first);
        curCap--;
    }
    if(s.count(key) > 0) {
        q.erase(s[key].first);
        curCap--;
    }
    curCap++;
    q[tim] = key;
    s[key] = {tim++, value};
}