#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        map<int,int> m;
        m[0]=0;
        for(int i=0;i<ranges.size();i++)
        {
            int upper = i+ranges[i];
            auto it = m.lower_bound(i-ranges[i]);
            if(ranges[i]==0 || it==m.end()) continue;
            if(m.count(upper)>0) m[upper]=min(it->second+1,m[upper]);
            else m[upper] = it->second+1;
            it = m.find(upper);
            if(next(it)!=m.end() && next(it)->second<=it->second) m.erase(it);
            else while(prev(it)!=m.begin() && prev(it)->second>=it->second) m.erase(prev(it));
        }
        for(auto& [k,v] : m) if(k>=n) return v;
        return -1;
    }
};