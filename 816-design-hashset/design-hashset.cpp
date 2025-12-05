class MyHashSet {
public:
    unordered_map<int,int>map;
    MyHashSet() {
        
    }
    
    void add(int key) {
        map[key]++;
    }
    
    void remove(int key) {
        if(map.find(key)!=map.end()){
            map.erase(key);
        }
    }
    
    bool contains(int key) {
        if(map.find(key)!=map.end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */