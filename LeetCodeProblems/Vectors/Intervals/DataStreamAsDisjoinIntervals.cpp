#include <map>
#include <vector>
using namespace std;

class SummaryRanges {
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        auto it = m.lower_bound(value);
        if(it!=m.end() && it->first==value+1)
        {
            m[value]=it->second;
            m.erase(it);
        }
        else if(it==m.end() || it->first!=value) m[value]=value;
        it = m.lower_bound(value);
        if(it!=m.begin() && prev(it)->second>=value-1)
        {
            prev(it)->second = max(prev(it)->second,m[value]);
            m.erase(value);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> v;
        for(auto& [first,second] : m) v.push_back({first,second});
        return v;
    }
private:
    map<int,int> m;
};