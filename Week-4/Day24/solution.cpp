class LRUCache {
public:
    int cap;
    list<int> myList;
    list<int>:: iterator it;
    unordered_map<int, int> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        myList.clear();
    }
    
    int get(int key) {
        if( mp[key] && mp[key] != -1 ) {
            // get the value and put it to the first
            for(it = myList.begin(); it != myList.end(); it++) {
                if( *it == key ) {
                    myList.erase(it);
                    break;
                }
            }
            myList.push_back(key);
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if( mp[key] && mp[key] != -1 ) {
            for(it = myList.begin(); it != myList.end(); it++) {
                if( *it == key ) {
                    myList.erase(it);
                    break;
                }
            }
            myList.push_back(key);
            mp[key] = value;
            return;
        }
        if( myList.size() == cap ) {
            int top = myList.front();
            myList.pop_front();
            mp[top] = -1;
        }
        myList.push_back(key);
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */