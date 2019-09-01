unordered_map<int,int> value;
map<long long int, int> recent;
unordered_map<int, long long int> recentRev;
int num;

void insert(int key, int value2)
{
    if(value.size() ==  0) {
       recent[1ll*num] = key;
       value[key] = value2;
       recentRev[key] = 1ll*num;
   }
   else
   {
       long long int trash = (recent.begin()->first)-1ll; 
        recent[trash] = key;
        value[key] = value2;
        recentRev[key] = trash;
   }
}

void removal()
{
    if(recent.size() > 0)
   {
       recentRev.erase(recent.rbegin()->second);
       value.erase(recent.rbegin()->second);
       recent.erase(recent.rbegin()->first);
   }   
}

LRUCache::LRUCache(int capacity) {
   value.clear();
   recent.clear();
   recentRev.clear();
   num = capacity;
}

int LRUCache::get(int key) {
    if(value.count(key) == 0) return -1;
    else {
        set(key,value[key]);
        return value[key];
    }
}

void LRUCache::set(int key, int value2) {
   if(value.count(key) == 0)
   {
       if(value.size() >= num)
       {
           removal();
       }
   }else
   {
        if(recent.size() > 0)
       {
           int trash = recentRev[key];
           recentRev.erase(key);
           value.erase(key);
           recent.erase(trash);
       }   
   }
   insert(key,value2);
}
