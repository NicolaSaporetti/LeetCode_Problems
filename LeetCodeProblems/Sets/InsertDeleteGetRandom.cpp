#include <iostream>
#include <set>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand (time(NULL));
    }
    
    bool insert(int val) {
        bool res = false;
        if(s.find(val)==s.end()) res= true;
        s.insert(val);
        return res;
    }
    
    bool remove(int val) {
        bool res = false;
        if(s.find(val)!=s.end()) res= true;
        s.erase(val);
        return res;
    }
    
    int getRandom() {
        int sz = s.size();
        int v = rand()%sz;
        auto it = s.begin();
        advance(it, v);
        return *it;
    }
private:
    set<int> s;
};