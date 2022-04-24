#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        table.resize(1000001);
    }
    
    void add(int key) {
        table[key] = true;
    }
    
    void remove(int key) {
        table[key] = false;
    }
    
    bool contains(int key) {
        return table[key];
    }
    vector<bool> table;
};

int main()
{
    MyHashSet obj;
    obj.add(3);
    obj.remove(3);
    bool param_3 = obj.contains(2);
}