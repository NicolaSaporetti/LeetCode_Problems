#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.count(key)>0)
        {
            l.push_front(key);
            l.erase(m[key].second);
            m[key].second=l.begin();
            return m[key].first;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)>0) l.erase(m[key].second);
        l.push_front(key);
        m[key] = {value,l.begin()};
        if(m.size()>cap)
        {
            m.erase(*l.rbegin());
            l.pop_back();
        }
    }
private:
    int cap;
    unordered_map<int,pair<int,std::list<int>::iterator>> m;
    list<int> l;
};