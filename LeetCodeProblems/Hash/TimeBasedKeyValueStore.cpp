#include <unordered_map>
#include <map>
using namespace std;

class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(m.count(key)==0) return "";
        else
        {
            auto it = m[key].upper_bound(timestamp);
            return (it==m[key].begin())? "" : prev(it)->second;
        }
    }
private:
    unordered_map<string,map<int,string>> m;
};