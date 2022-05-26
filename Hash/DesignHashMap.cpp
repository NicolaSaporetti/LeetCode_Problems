#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
public:
    MyHashMap() {
        table.resize(1000001);
        for(int i=0;i<1000001;i++)
        {
            table[i]=-1;
        }
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

int main()
{
    MyHashMap obj;
    obj.put(3,3);
    obj.remove(3);
    bool param_3 = obj.get(2);
}