#include <vector>
using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        set.assign(1000001,false);
    }
    
    void add(int key) {
        set[key]=true;
    }
    
    void remove(int key) {
        set[key]=false;
    }
    
    bool contains(int key) {
        return set[key];
    }

    vector<bool> set;
};