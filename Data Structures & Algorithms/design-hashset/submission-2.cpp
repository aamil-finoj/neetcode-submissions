class MyHashSet {
public:

    bool arr[1000001] = {false};

    MyHashSet() {
        

    }
    
    void add(int key) {
        arr[key] = true;
    }
    
    void remove(int key) {
        arr[key] = false;
    }
    
    bool contains(int key) {
        return arr[key];
    }
};

/**
 * Your MyHasharr object will be instantiated and called as such:
 * MyHasharr* obj = new MyHasharr();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */