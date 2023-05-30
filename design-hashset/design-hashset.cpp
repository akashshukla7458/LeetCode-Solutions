class MyHashSet {
public:
vector<bool>table;
    MyHashSet(): table(1e6+1, 0) {}
        
    
    
    void add(int key) {
        table[key]=1;
    }
    
    void remove(int key) {
        table[key]=0;
    }
    
    bool contains(int key) {
        return table[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */