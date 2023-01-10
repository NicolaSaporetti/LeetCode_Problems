#include <vector>
using namespace std;

class MyHashMap {
public:
    MyHashMap() {
        table.assign(1000001,-1);
    }
    
    void put(int key, int value) {
        table[key]=value;
    }
    
    int get(int key) {
        return table[key];
    }
    
    void remove(int key) {
        table[key] = -1;
    }
    vector<int> table;
};