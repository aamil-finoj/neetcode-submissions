class MyHashSet {
public:

    int arr[10000001] = {0};

    MyHashSet() {
        

    }
    
    void add(int key) {
        arr[key] = 1;
    }
    
    void remove(int key) {
        arr[key] = 0;
    }
    
    bool contains(int key) {
        return (arr[key] == 1 ? true : false);
    }
};

/**
 * Your MyHasharr object will be instantiated and called as such:
 * MyHasharr* obj = new MyHasharr();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */