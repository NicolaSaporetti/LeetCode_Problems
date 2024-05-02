#include <unordered_map>
#include <unordered_set>
using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int freq = el[number];
        m[freq].erase(number);
        m[freq+1].insert(number);
        el[number]=freq+1;
    }
    
    void deleteOne(int number) {
        if(!el.count(number)) return;
        int freq = el[number];
        m[freq].erase(number);
        if(freq>1)
        {
            m[freq-1].insert(number);
            el[number]=freq-1;
            
        }
        else el.erase(number);
    }
    
    bool hasFrequency(int frequency) {
        return !m[frequency].empty();
    }
private:
    unordered_map<int,unordered_set<int>> m;
    unordered_map<int,int> el;
};