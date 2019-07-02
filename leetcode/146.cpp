class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) { }
    
    int get(int key) {
        if(!v.count(key)) return -1;
        
        update(key);
        return v[key];
    }
    
    void put(int key, int value) {
        if(v.size() == cap  && !v.count(key)) deleteOldest();
        
        update(key);
        v[key] = value;
    }
private:
    unordered_map<int, int> v;                  /* key -> val */
    unordered_map<int, list<int>::iterator > l; /* key -> iterator */
    list<int> lru;                              /* LRU */ 
    
    int cap;
    
    void update(int key) {
        if(v.count(key)) lru.erase( l[key] );
        
        lru.push_front(key);
        l[key] = lru.begin();
    }
    
    void deleteOldest() {
        v.erase(lru.back());
        l.erase(lru.back());
        lru.pop_back();
    }
};
